#include <stdio.h>
#include <malloc.h>
#include <memory.h>
template <typename T>
void swap(T& a, T& b) {
	T t;
	t = a; a = b; b = t;
}

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

template <typename T>
T cast(int s) {
	return (T)s;
}

template <typename T>
void swaparray(T* a, T* b, int num) {
	void* t;

	t = malloc(num * sizeof(T));

	memcpy(t, a, num * sizeof(T));
	memcpy(a, b, num * sizeof(T));
	memcpy(b, t, num * sizeof(T));

	free(t);

}

//int main() {
//	int a = 3, b = 5;
//	double c = 1.2, d = 3.4;
//	char e = 'A', f = 'B';
//
//	swap(a, b);
//	swap(c, d);
//	swap(e, f);
//	printf("a = %d, b = %d \n", a, b);
//	printf("a = %f, b = %f \n", c, d);
//	printf("a = %c, b = %c \n", e, f);
//
//	int aa = max(1, 2);
//	double bb = max(1.1, 2.2);
//	int cc = max<int>(2, 3.14);
//
//	printf("cc = %d\n", cc);
//
//	unsigned u = cast<unsigned>(1234);
//	double dd = cast<double>(5678);
//	printf("u = %d, dd = %f\n", u, dd);
//
//
//	int ar[] = { 1,2,3 }, br[] = { 4,5,6 };
//	char cr[] = "¹®ÀÚ¿­", dr[] = "string";
//
//	printf("ar = ");
//	for (int i = 0; i < 3; i++) {
//		printf("%d ", ar[i]);
//	}
//	swaparray(ar, br, sizeof(ar) / sizeof(ar[0]));
//	printf(" --> ar = ");
//	for (int i = 0; i < 3; i++) {
//		printf("%d ", ar[i]);
//	}
//	puts("");
//
//	printf("before cr = %s, dr = %s\n", cr, dr);
//	swaparray(cr, dr, sizeof(cr) / sizeof(cr[0]));
//	printf("after cr = %s, dr = %s\n", cr, dr);
//}