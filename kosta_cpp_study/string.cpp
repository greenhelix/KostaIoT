#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("test");
	string s2(s1);
	string s3;
	string s4(10, 'S');
	string s5("very nice day", 9);
	const char* str = "abcdefghijklmnopqrstuvwxyz";
	string s6(str + 5, str + 10);

	cout << "s1=" << s1 << endl;	//s1 = test
	cout << "s2=" << s2 << endl; 	//s2 = test
	cout << "s3=" << s3 << endl; 	//s3 =
	cout << "s4=" << s4 << endl; 	//s4 = SSSSSSSSSS
	cout << "s5=" << s5 << endl; 	//s5 = very nice
	cout << "s6=" << s6 << endl; 	//s6 = fghij

	string s("C++ string");

	cout << s << " 문자열의 길이 = " << s.size() << endl;  	//C++ string 문자열의 길이 = 10
	cout << s << " 문자열의 길이 = " << s.length() << endl; //C++ string 문자열의 길이 = 10
	cout << s << " 문자열의 할당 크기 = " << s.capacity() << endl; //C++ string 문자열의 할당 크기 = 15
	cout << s << " 문자열의 최대 길이 = " << s.max_size() << endl; //C++ string 문자열의 최대 길이 = 9223372036854775807


	s.resize(6);
	cout << s << " 길이 = " << s.size() << ",할당 크기 = " << s.capacity() << endl; //C++ st 길이 = 6, 할당 크기 = 15
	s.reserve(100);
	cout << s << " 길이 = " << s.size() << ",할당 크기 = " << s.capacity() << endl;  //C++ st 길이 = 6, 할당 크기 = 111

	puts("==========================================");
	string ss("char array");

	cout << ss.data() << endl; //char array
	cout << ss.c_str() << endl; //char array

	char strr[128];
	strcpy_s(strr, ss.c_str());
	printf("str = %s\n", strr); //str = char array
	
	string s11("aaa");
	string s22("bbb");

	cout << (s11 == s11 ? "같다" : "다르다") << endl;
	cout << (s11 == s22 ? "같다" : "다르다") << endl;
	cout << (s11 > s22 ? "크다" : "안크다") << endl;

	string s33("1234567");
	string s44("1234999");
	cout << (s33.compare(s44) == 0 ? "같다" : "다르다") << endl;
	cout << (s33.compare(0, 4, s44, 0, 4) == 0 ? "같다" : "다르다") << endl;

	string s55("hongkildong");
	cout << (s55 == "hongkildong" ? "같다" : "다르다") << endl;

	string sa("string class finding function");
	string sb("func");


	// 발견된 첫번째 'i'인덱스를 가져와라
	cout << "i:" << sa.find('i') << "번째" << endl;

	// 10번 인덱스부터 'i'의 인덱스를 찾아라
	cout << "i:" << sa.find('i', 10) << "번째" << endl;

	// 'ass'문자열 첫 시작 인덱스를 찾아라
	cout << "ass:" << sa.find("ass") << "번째" << endl;

	cout << "finding의 앞 4:" << sa.find("finding", 0, 4) << "번째" << endl;
	cout << "kiss:" << sa.find("kiss") << "번째" << endl;
	cout << sb << ':' << sa.find(sb) << "번째" << endl;
}