#include <stdio.h>
#include "header.h"

// 이렇게 계속 올리면 많아지고 길어지므로 이러한 함수들을 파일로 구분해준뒤
// 헤더파일로 만들어준다. 
// include를 통해서 가져온다. 

int main()
{
	// 변수
	whatIsVariable();
	whatIsEnum();
	whatIsPointer();
	whatIsScanf();
	whatIsCursor();

	// 연산자
	whatIsArithmatic(); //산술연산자
	whatIsModular(); // 나머지연산자
	whatIsPrepost(); // 
	whatIsPriority();
	whatIsConvert();
	whatIsCast();
}