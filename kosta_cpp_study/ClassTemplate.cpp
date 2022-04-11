#include <cursor.h>
#include <iostream>
using namespace std;

template <typename T>
class PostValue {
private:
	int x, y;
	T value;
public:
	PostValue(int ax, int ay, T av): x(ax), y(ay), value(av){}
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

//int main() {
//	PostValue<int> iv(10, 10, 2);
//	PostValue<char> cv(25, 5, 'C');
//	PostValue<double> dv(30, 15, 3.14);
//	iv.outvalue();
//	cv.outvalue();
//	dv.outvalue();
//}