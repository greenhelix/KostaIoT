#include <iostream>
#include <iterator>
#include <set>
using namespace std;


//int main() {
//
//	set<int> a = { 6, 10, 5, 1, 12, 4 };
//
//	// 그냥 출력하면 내림차순 입니다. greater를 직접 사용하여 출력해보세요.
//
//	//#1 반복자 생성
//	set<int >::iterator p;
//	set<int>::reverse_iterator rp;
//	//#2 새로운 Set선언
//	set<int> s2(a.begin(), a.end());
//
//	//#3 반복문 통해 출력하기
//	for (p = s2.begin(); p != s2.end(); p++) {
//		cout << *p << " ";
//	}
//	cout << endl;
//	for (rp = s2.rbegin(); rp != s2.rend(); ++rp) {
//		cout << *rp << " ";
//	}
//
//
//
//	multiset<int, greater<int> > gquiz1;
//
//	// insert elements in random order
//	gquiz1.insert(40);
//	gquiz1.insert(30);
//	gquiz1.insert(60);
//	gquiz1.insert(20);
//	gquiz1.insert(50);
//
//	// 50 will be added again to
//	// the multiset unlike set
//	gquiz1.insert(50);
//	gquiz1.insert(10);
//
//	// printing multiset gquiz1
//	multiset<int, greater<int> >::iterator itr;
//	cout << "\nThe multiset gquiz1 is : \n";
//	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
//		cout << *itr << " ";
//	}
//	cout << endl;
//
//	// assigning the elements from gquiz1 to gquiz2
//	multiset<int> gquiz2(gquiz1.begin(), gquiz1.end());
//
//	// print all elements of the multiset gquiz2
//	cout << "\nThe multiset gquiz2 \n"
//		"after assign from gquiz1 is : \n";
//	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
//		cout << *itr << " ";
//	}
//	cout << endl;
//
//	// 출력 
//
//	/*set<int> sample = { 6, 10, 5, 1, 12, 4, 5, 5};
//
//	set<int>::iterator aa;
//
//	for (aa = sample.begin(); aa != sample.end(); aa++) {
//		cout << *aa << ",";
//	}*/
//
//	//set<int> val;
//	//val.insert(10);
//	//val.insert(11);
//	//val.insert(12);
//	/*set<int> val2 = { 6, 10, 5, 1 };
//
//	for (int i = 0; i < val2.size(); i++) {
//		cout << val2[i] << ",";
//	}*/
//	//cout << endl;
//	//set<int, greater<int>> val3;
//	//val3.insert(123);
//	//val3.insert(1123);
//	//val3.insert(124);
//
//	//set<int>::iterator aa;
//
//	//for (aa = val3.begin(); aa != val3.end(); aa++) {
//	//	cout << *aa << ",";
//	//}
//
//}