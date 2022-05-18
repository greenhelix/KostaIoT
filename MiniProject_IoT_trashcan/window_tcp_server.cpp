#define WIN32_LEAN_AND_MEAN
#include <opencv2/opencv.hpp>
#include <iostream>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define point1_y 37.470023  //지도 잘라올 사각형 점위치 왼쪽아래
#define point1_x 126.882420
#define point2_y 37.474518 //오른쪽 위
#define point2_x 126.891336


#define DEFAULT_BUFLEN 128
#define DEFAULT_PORT "5100"

using namespace cv;
//using namespace std;

using std::string;
double ID[3]; //ID[0] 세로 위치 | ID[1] 가로 | 위치 ID[2] 쓰레기통 아이디
int i = 0; //반복문용


int __cdecl main(int argc, char** argv)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;
    SOCKADDR_IN  clntAddr;
    int szClntAddr;
    struct addrinfo* result = NULL;
    struct addrinfo hints;
    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    const char* imageName = argc >= 2 ? argv[1] : "map.jpg";
    Mat img = imread(imageName, IMREAD_COLOR);
    Mat img2;


    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }
    printf("11");
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }
    printf(">>");
    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }
    printf(">>");
    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    printf(">>");
    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    printf(">>");
    szClntAddr = sizeof(clntAddr);

    // Accept a client socket
    ClientSocket = accept(ListenSocket, (SOCKADDR*)&clntAddr, &szClntAddr);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    printf(">>");
    // No longer need server socket
    closesocket(ListenSocket);
    printf(">>");
    // Receive until the peer shuts down the connection
    while (i < 3) { //3번 반복
        do {
            double recv_position;
            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0) {
                printf("Bytes received: %d\n", iResult);
                ID[i] = atof(recvbuf); // Y 값부터 차례대로 넣음 문자열에서 double형으로 변환
                i++;
                std::cout << ID[i] << std::endl; //디버그용
                // Echo the buffer back to the sender
                iSendResult = send(ClientSocket, recvbuf, iResult, 0);
                if (iSendResult == SOCKET_ERROR) {
                    printf("send failed with error: %d\n", WSAGetLastError());
                    closesocket(ClientSocket);
                    WSACleanup();
                    return 1;
                }
                printf("Bytes sent: %d\n", iSendResult);
            }
            /*else if (iResult == 0)
                printf("Connection closing...\n");
            else {
                printf("recv failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }*/

        } while (iResult > 0);
    }

    i = 0;

    while (1) {
        //double y = 37.472367, x = 126.886274; //호서대벤처타워 위치 찍어보기용
        double y = ID[0], x = ID[1]; //통신으로 받은 배열에 저장된 값 가져옴
        std::cout << y << "  " << x << std::endl;//디버그용
        double width = point2_x - point1_x; //좌표상 폭
        double height = point2_y - point1_y; //좌표상 높이
        double map_width = img.cols, map_height = img.rows; // 사진 가로 세로 크기(픽셀단위)
        double normal_x = (x - point1_x) / width; // 받아온 가로 위치(경도) 정규화
        double normal_y = (y - point1_y) / height; //받아온 세로 위치(위도) 정규화

        int map_x = normal_x * map_width; //정규화된 값 이미지 파일의 픽셀 위치상 절대값 구함
        int map_y = normal_y * map_height;
        std::cout << map_x << std::endl; //디버그용

        img2 = img; //이미지 배열 복사
        circle(img2, Point(map_x, map_height - map_y), 10, Scalar(0, 0, 255), 4, 4, 0);
        //복사한 배열에 원 그리기
        imshow("find", img2);
        //복사한 배열에 원 그린 배열 출력

        char c = (char)waitKey();
        if (c == 27) //ESC 누르면 종료
        {
            return 0;
        }
    }

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}