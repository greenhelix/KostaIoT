#include <iostream>
#define PI 3.14; 

using namespace std;

class one {
private:
    int x, y;
    double wide;

public:
    one(int r) {
        wide = PI * r ^ 2;
    }

    void result() {
        cout << "원의 넓이는" << wide << "입니다" << endl;
    }
};

int main() {
    /*
   int a=1;
   cout << "반지름을 입력하쎄오" << endl;
   cin >> a;
   one jir(a);
   jir.result();
*/
}