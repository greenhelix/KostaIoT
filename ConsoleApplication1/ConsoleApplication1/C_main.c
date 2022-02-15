#include <stdio.h>
#include "c언어기본헤더.h"
// 이렇게 계속 올리면 많아지고 길어지므로 이러한 함수들을 파일로 구분해준뒤
// 헤더파일로 만들어준다. 
// include를 통해서 가져온다. 

int main()
{
	// 기본 변수명들의 사용법
	whatIsVariable();

	// 열거형 enum  일정한 범위의 값만 가능한 타입 
	// enum{멤버, 멤버,...} 변수명;  예) enum{EAST, WEST, SOUTH, NORTH} mark;
	// enum{MAN = 1, WOMAN = 2, GIRL = 2} human; 이렇게 값이 중복은 가능하다.동일한 것으로 인식
	whatIsEnum();

	// struct 서로 다른 변수명을 모아둘 수 있다. 
	struct {
		char title[10];
		char singer[10];
		double length;
		int size;
	} song;

	// pointer 포인터를 경유하여 간접적으로 값에 접근한다.
	whatIsPointer();

	// 사용자 정의형
	whatIsTypeDef();

	// 진위형 Boolean true = 1, false = 0 
	whatIsDefine();
}
