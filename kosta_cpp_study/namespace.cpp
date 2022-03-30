#include <stdio.h>

namespace A {
	double value;
}

namespace B {
	int value;
}

int values;
namespace C {
	int value;
}

// 중첩된 명칭 참조 방법
namespace Game {
	namespace Graphic {
		struct Screen {};
	}
	namespace Sound {
		struct Sori {};
	}
}

namespace UTIL {
	int value;
	double score;
	void sub() { puts("sub routine"); }
}

//int main() {
//	int value;
//	value = 1; // 지역변수 value
//
//	A::value = 12.345;
//	B::value = 123;
//
//	::values = 2; // 전역변수 value
//	C::value = 3; // namespace C의 value
//
//	Game::Graphic::Screen hi; 
//
//	using UTIL::value;
//
//	value = 3; //소속지정x
//	UTIL::score = 1.2345;
//	UTIL::sub();
//}

void mysub()
{
	UTIL::value = 5; //소속지정o
}