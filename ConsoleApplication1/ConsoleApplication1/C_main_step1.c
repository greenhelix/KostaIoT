#include <stdio.h>
#include "step1.h"

// 이렇게 계속 올리면 많아지고 길어지므로 이러한 함수들을 파일로 구분해준뒤
// 헤더파일로 만들어준다. 
// include를 통해서 가져온다. 
void variable() {
	whatIsVariable();

	whatIsEnum();

	struct {
		char title[10];
		char singer[10];
		double length;
		int size;
	} song; // struct 구조형 - 다른 타입의 변수 집합


	int arScore[10]; // array 배열형 -  같은 타입의 변수 집합
	int sum = 0; //for (int i = 0; i < 10; i++) sum += arScore[i];

	whatIsPointer();

	whatIsTypeDef(); // 사용자 정의형

	whatIsDefine(); // 진위형 Boolean true = 1, false = 0 

	whatIsScanf(); // 스캐너

	whatIsCursor(); // 커서
}

int main()
{
	
	//variable();

	// 연산자
	//whatIsArithmatic(); //산술연산자
	//whatIsModular(); // 나머지연산자
	//whatIsPrepost(); // 
	//whatIsPriority();
	//whatIsConvert();
	whatIsCast();
}


