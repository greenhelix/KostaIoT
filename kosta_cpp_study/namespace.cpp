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

// ��ø�� ��Ī ���� ���
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
//	value = 1; // �������� value
//
//	A::value = 12.345;
//	B::value = 123;
//
//	::values = 2; // �������� value
//	C::value = 3; // namespace C�� value
//
//	Game::Graphic::Screen hi; 
//
//	using UTIL::value;
//
//	value = 3; //�Ҽ�����x
//	UTIL::score = 1.2345;
//	UTIL::sub();
//}

void mysub()
{
	UTIL::value = 5; //�Ҽ�����o
}