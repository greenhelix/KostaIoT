#include <stdio.h>
#pragma warning (disable : 4996)
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
// file IO mode: 
/*
r: read only
w: write only, if not file, make new file and write
a: end of file open, add other info.. if not file, new make file
r+ : read, write, if not file, return error
a+ : read, add , if not file, make new file
*/ 

void MakeTextFile()
{
	FILE* f;
	char* str = "이 파일은 C표준 함수로 생성된 텍스트 파일입니다.\n"
		"C드라이브의 Temp 디렉토리에 Text.txt라는 이름으로 생성됩니다.\n";
	f = fopen("c:\\Temp\\Test.txt", "wt");

	if (f == NULL)
	{
		puts("파일 생성 실패 - 파일 경로에 폴더가 있는지 확인하세요.");
	}
	else {
		fputs(str, f);
		puts("파일이 정상적으로 생성 되었습니다.");
		fclose(f);
	}

	char buf[2048]; //256,2048 등으로 크기를 조절하는데, 환경에 따라서..

	f = fopen("c:\\Temp\\Test.txt", "rt"); // read하기위해서 다시 파일 오픈

	if (f != NULL)
	{
		for (;;) {
			// fgets 파일안에 들어있는 것을 가져온다. buf는 어디에, 256은 크기, f는 해당 파일
			if (fgets(buf, 256, f) == NULL) {
				break;
			}
			printf("%s", buf);
		}
		fclose(f);
	}
}

void BlockIO()
{
	FILE* src, * dest;
	char buf[256];
	size_t nRead;

	src = fopen("c:\\Temp\\Test.txt", "rb");
	
	if (src != NULL) {
		dest = fopen("c:\\Temp\\Test2.txt", "wb");
		if (dest != NULL)
		{
			while (!feof(src)) {
				nRead = fread(buf, 1, 256, src);
				fwrite(buf, 1, nRead, dest);
			}
			fclose(dest);
		}
		fclose(src);
	}
}

void randomaccess()
{
	FILE* f;
	char buf[256];

	f = fopen("c:\\Temp\\Test.txt", "rt");
	if (f != NULL) {
		fseek(f, 24, SEEK_SET);
		//fseek(f, 24, SEEK_CUR);
		//fseek(f, -4, SEEK_END);
		fgets(buf, 256, f);
		printf("%s", buf);
		fclose(f);
	}
}

void AddCountAccess()
{
	FILE* fp;
	char buf[5];
	fp = fopen("c:\\Temp\\AddCount.txt", "r+");
	
	fgets(buf, 5, fp);
	int pos;
	for (int i = 0; i < 5; i++)
	{
		if (buf[i] == '#')
		{
			fseek(fp, i + 1, SEEK_SET);
			fputs("2", fp);
			break;
		}
	}

	fclose(fp);

}

// 파일 다루기 : 저수준 IO 에서 파일 열고 닫기 
/*
_O_BINARY :이진모드로 연다.
_O_TEXT : 텍스트 모드로 연다.
_O_CREAT : 새로 만든다, 이미 있으면 아무것도 안한다.
_O_RDONLY : 읽기 전용
_O_RDWR : 읽기 쓰기 가능
_O_WRONLY : 쓰기 전용
_O_TRUNC : 파일 열고 크기 0으로 만든다. 
_O_APPEND : fp 파일 끝으로 보낸다.
_O_RANDOM : 캐시를 임의 접근, 최적화
_O_SEQUENTIAL : 캐시 순차 접근, 최적화
_O_SHORT_LIVED : 임시파일 생성, 
_O_TEMPORARY : 파일 닫을 시 삭제 
_O_EXCL : 파일 존재시 에러 리턴 
*/
void FileOpenClose()
{
	int file;
	char buf[256] = { 0, };

	file = _open("c:\\Temp\\Test.txt",  _O_RDONLY);
	if (file != -1) {
		//_read(file, buf, 256);
		printf("%s", buf);
		_close(file);
	}

}