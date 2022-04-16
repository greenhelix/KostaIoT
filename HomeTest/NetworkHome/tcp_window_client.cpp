#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")

using std::string;
#define DEFAULT_BUFLEN 512

#define DEFAULT_PORT "5100" // 포트 번호 설정

// C DECLaration  = __cdecl
// 함수 호출용으로 스택에 쌓은 파라미터를 호출한 함수에서 제거해 주는 Convention이다.
int __cdecl main(int argc, char **argv)
{

    // The WSADATA structure contains information
    // about the Windows Sockets implementation.
    WSADATA wasData;

    // 연결을 위한 소켓 생성
    SOCKET ConnectSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL, *ptr = NULL, hints;

    char sendbuf[BUFSIZ];         // 보내는 메세지 버퍼
    char recvbuf[DEFAULT_BUFLEN]; // 받는 메세지 버퍼

    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    printf("Hello TCP/IP network Test +++++\n");

    if (argc != 2)
    {
        printf("usage server name : %s \n", argv[0]);
        return 1;
    }

    // A pointer to the WSADATA data structure
    // that is to receive details of the Windows Sockets implementation.
    iResult = WSAStartup(MAKEWORD(2, 2), &wasData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error : %d\n", iResult);
        return 1;
    }

    // 서버 주소를 알기위해 필요한 정보를 가져온다?
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // 서버 주소와 포트 해결
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);

    // 주소와 포트가 안가져와진다면 아래 문구가 뜬다.
    if (iResult != 0)
    {
        printf("주소 정보가 에러 : %d\n", iResult);
        WSACleanup();
        return 1;
    }
    else
    {
        printf("주소 정보를 잘 가져왔다 : %d\n", iResult);
    }

    // 연결 성공할 때까지 계속 시도한다. 해당 주소로.
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        // 서버와 연결을 위한 소켓 생성 // 포인터를 활용해서 파라미터를 넣어준다.
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        // 잘 생성되었는지 확인
        if (ConnectSocket == INVALID_SOCKET)
        {
            printf("SOCKET ERROR %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }
        else
        {
            printf("SOCKET:GOOD!\n");
        }

        // 서버와 연결한다.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

        if (iResult == SOCKET_ERROR)
        {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result); //반복문에 사용된 Result를 초기화

    if (ConnectSocket == INVALID_SOCKET)
    {
        printf("서버 연결 실패 FAIL CONNECT SERVER!!\n");
        WSACleanup();
        return 1;
    }

    // 클라이언트로서 입력할 데이터
    // 테스트를 위해 문자열을 입력해본다.
    fgets(sendbuf, BUFSIZ, stdin);

    // 보내기 메서드를 통해 해당 내용을 소켓에 태운다.
    iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);

    // 보내는 메세지 소켓이 잘 안되면 뜨는 에러
    if (iResult == SOCKET_ERROR)
    {
        printf("보낸 메세지 오류 : send message error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    else
    {
        printf("SEDN::: %s\n", sendbuf);
    }

    // 보내는 데이터 연결 종료
    iResult = shutdown(ConnectSocket, SD_SEND);

    // 안되면 오류 잡기
    if (iResult == SOCKET_ERROR)
    {
        printf("보낸 메세지 종료 오류 : send shutdown error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    else
    {
        printf("SEDN::: %s\n", sendbuf);
    }

    return 0;
}