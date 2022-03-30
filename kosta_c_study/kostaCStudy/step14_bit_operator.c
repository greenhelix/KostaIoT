#include <stdio.h>
#include <stdlib.h> 

void BitOperator()
{
	int a = 0x59;
	printf("not 0xf = %x\n", ~a);
	printf("and 0xf = %x\n", a & 0xf);
	printf("or 0xf = %x\n", a | 0xf);
	printf("xor 0xf = %x\n", a ^ 0xf);

	unsigned short han = 0x887c;
	if (((han & 0x7c00) >> 10) == 2) {
		puts("초성이 ㄱ입니다.");
	}
	else {
		puts("초성이 ㄱ이 아닙니다.");
	}

	int i = 12;
	printf("12 << 1 = %d\n", i << 1);
	printf("12 >> 1 = %d\n", i >> 2);
}

void BitRotate()
{
	unsigned value = 0x12345678;
	double test[] = { 1,2,3,4,5,6,7,8 };
	printf("value = %x\n", value);
	// 8bit = 1byte 
	printf("rot 4 = %x\n", _rotr(value, 4)); // 한칸 이동 오른쪽
	printf("rot 4 = %d\n", _rotr(test, 4)); // 한칸 이동 오른쪽

	printf("rot 8 = %x\n", _rotr(value, 8));
	printf("rot 16 = %x\n", _rotr(value, 16));

	int a = 0x12345678;
	int xor = 0x3a287cd9;

	int secret = _rotl(a^xor, 13);
	printf("암호화한 값 = %x\n", secret);
	int original = _rotr(secret, 13)^xor;
	printf("복원한 값 = %x\n", original);
}

struct Sbit {
	unsigned short a : 4;
	unsigned short b : 3;
	unsigned short c : 1;
	unsigned short d : 8;
};

void BitStruct()
{
	struct Sbit bit;
	bit.a = 0xf;
	bit.b = 3;
	bit.c = 1;
	bit.d = 0xab;
	printf("크기 = %d, 값 = %x\n", sizeof(bit), bit);
}

union UData
{
	int a; 
	short b[2];
};

void UnionBit()
{
	union UData un;
	un.a = 0x12345678;
	printf("un.a = %x\n", un.a);
	printf("un.b[0] = %x\n", un.b[0]);
	printf("un.b[1] = %x\n", un.b[1]);

	un.b[0] = (short)0x9999;
	printf("대입 후의 un.a = %x\n", un.a);
}