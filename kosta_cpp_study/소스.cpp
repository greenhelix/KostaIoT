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
        cout << "���� ���̴�" << wide << "�Դϴ�" << endl;
    }
};

int main() {
    /*
   int a=1;
   cout << "�������� �Է��Ͻ��" << endl;
   cin >> a;
   one jir(a);
   jir.result();
*/
}