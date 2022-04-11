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
	char* str = "�� ������ Cǥ�� �Լ��� ������ �ؽ�Ʈ �����Դϴ�.\n"
		"C����̺��� Temp ���丮�� Text.txt��� �̸����� �����˴ϴ�.\n";
	f = fopen("c:\\Temp\\Test.txt", "wt");

	if (f == NULL)
	{
		puts("���� ���� ���� - ���� ��ο� ������ �ִ��� Ȯ���ϼ���.");
	}
	else {
		fputs(str, f);
		puts("������ ���������� ���� �Ǿ����ϴ�.");
		fclose(f);
	}

	char buf[2048]; //256,2048 ������ ũ�⸦ �����ϴµ�, ȯ�濡 ����..

	f = fopen("c:\\Temp\\Test.txt", "rt"); // read�ϱ����ؼ� �ٽ� ���� ����

	if (f != NULL)
	{
		for (;;) {
			// fgets ���Ͼȿ� ����ִ� ���� �����´�. buf�� ���, 256�� ũ��, f�� �ش� ����
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

// ���� �ٷ�� : ������ IO ���� ���� ���� �ݱ� 
/*
_O_BINARY :�������� ����.
_O_TEXT : �ؽ�Ʈ ���� ����.
_O_CREAT : ���� �����, �̹� ������ �ƹ��͵� ���Ѵ�.
_O_RDONLY : �б� ����
_O_RDWR : �б� ���� ����
_O_WRONLY : ���� ����
_O_TRUNC : ���� ���� ũ�� 0���� �����. 
_O_APPEND : fp ���� ������ ������.
_O_RANDOM : ĳ�ø� ���� ����, ����ȭ
_O_SEQUENTIAL : ĳ�� ���� ����, ����ȭ
_O_SHORT_LIVED : �ӽ����� ����, 
_O_TEMPORARY : ���� ���� �� ���� 
_O_EXCL : ���� ����� ���� ���� 
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