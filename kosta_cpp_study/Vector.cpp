
// 벡터는 자주 사용되는 자료구조 
#include <vector>
#include <iostream>
using namespace std;


// 벡터 초기화 선언 가능하다.
//int main() {
//
//	char a1[3];
//	int a2[10];
//
//	// 배열 사이즈에 변수 선어하여 넣기 안 됨
//	//int na = 4;
//	//int a3[na];
//
//	for (char x : a1) cout << x << ", ";
//	cout << endl;
//	for (int x : a2) cout << x << ", "; 
//
//	puts("\n----------------------");
//
//	vector<int>* test1 = new vector<int>(12);
//	vector<int> *test2 = new vector<int>;
//
//	puts("test1: ");
//	for (int x : *test1) cout << x << ",";
//	puts("\ntest2: ");
//	for (int x : *test2) cout << x << ",";
//
//	puts("\n----------------------");
//
//	vector<char> v1(3);
//	vector<int> v2(10);
//	int n = 4;
//	vector<int> v3(n);
//
//	for (char x : v1) cout << x << ",";
//	cout << endl;
//	for (int x : v2) cout << x << ",";
//	cout << endl;
//	for (int x : v3) cout << x << ",";
//
//	puts("\n----------------------");
//
//	vector<int> v4(5, 2);
//	for (int x : v4) cout << x << ",";
//	
//	puts("\n----------------------");
//
//	vector<int> test11(5, 2);
//
//	cout << "test1 = "; for (int x : test11) cout << x << " ";
//	cout << endl;
//
//	int nn = 4;
//	vector<int> test22(nn, 1);
//
//	cout << "test2 = "; for (int x : test22) cout << x << " ";
//	cout << endl;
//
//	vector<int> sample3{ 1 , 2, 3, 4, 5 };
//	vector<int> sample4 = { 1 , 2, 3, 4, 5 };
//	cout << "sample3 = "; for (int x : sample3) cout << x << " ";
//	cout << "sample4 = "; for (int x : sample4) cout << x << " ";
//
//}