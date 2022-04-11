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

	cout << s << " ���ڿ��� ���� = " << s.size() << endl;  	//C++ string ���ڿ��� ���� = 10
	cout << s << " ���ڿ��� ���� = " << s.length() << endl; //C++ string ���ڿ��� ���� = 10
	cout << s << " ���ڿ��� �Ҵ� ũ�� = " << s.capacity() << endl; //C++ string ���ڿ��� �Ҵ� ũ�� = 15
	cout << s << " ���ڿ��� �ִ� ���� = " << s.max_size() << endl; //C++ string ���ڿ��� �ִ� ���� = 9223372036854775807


	s.resize(6);
	cout << s << " ���� = " << s.size() << ",�Ҵ� ũ�� = " << s.capacity() << endl; //C++ st ���� = 6, �Ҵ� ũ�� = 15
	s.reserve(100);
	cout << s << " ���� = " << s.size() << ",�Ҵ� ũ�� = " << s.capacity() << endl;  //C++ st ���� = 6, �Ҵ� ũ�� = 111

	puts("==========================================");
	string ss("char array");

	cout << ss.data() << endl; //char array
	cout << ss.c_str() << endl; //char array

	char strr[128];
	strcpy_s(strr, ss.c_str());
	printf("str = %s\n", strr); //str = char array
	
	string s11("aaa");
	string s22("bbb");

	cout << (s11 == s11 ? "����" : "�ٸ���") << endl;
	cout << (s11 == s22 ? "����" : "�ٸ���") << endl;
	cout << (s11 > s22 ? "ũ��" : "��ũ��") << endl;

	string s33("1234567");
	string s44("1234999");
	cout << (s33.compare(s44) == 0 ? "����" : "�ٸ���") << endl;
	cout << (s33.compare(0, 4, s44, 0, 4) == 0 ? "����" : "�ٸ���") << endl;

	string s55("hongkildong");
	cout << (s55 == "hongkildong" ? "����" : "�ٸ���") << endl;

	string sa("string class finding function");
	string sb("func");


	// �߰ߵ� ù��° 'i'�ε����� �����Ͷ�
	cout << "i:" << sa.find('i') << "��°" << endl;

	// 10�� �ε������� 'i'�� �ε����� ã�ƶ�
	cout << "i:" << sa.find('i', 10) << "��°" << endl;

	// 'ass'���ڿ� ù ���� �ε����� ã�ƶ�
	cout << "ass:" << sa.find("ass") << "��°" << endl;

	cout << "finding�� �� 4:" << sa.find("finding", 0, 4) << "��°" << endl;
	cout << "kiss:" << sa.find("kiss") << "��°" << endl;
	cout << sb << ':' << sa.find(sb) << "��°" << endl;
}