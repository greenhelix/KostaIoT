#include <stdio.h>

class Unit {
public:
	virtual void running()= 0;
	virtual void flying()= 0;
	virtual void burrowing()= 0;
};

class Zillut : public Unit {
public:
	virtual void running() {
		puts("zillut is running!!!...\n"); 
	}
	virtual void flying() {
		puts("zillut is flying????\n");
	}
	virtual void burrowing() {
		puts("zillut cant burrowing\n");
	}
};

class Mutal : public Unit {
public:
	virtual void running() {
		puts("Mutal is running!!!.\n");
	}
	virtual void flying() {
		puts("Mutal is flying!!!\n");
	}
	virtual void burrowing() {
		puts("Mutal cant burrowing\n");
	}
};

class Dropship : public Unit {
public:
	virtual void running() {
		puts("Dropship cant running...\n");
	}
	virtual void flying() {
		puts("Dropship is flying!!!\n");
	}
	virtual void burrowing() {
		puts("Dropship cant burrowing\n");
	}
};

//int main() {
//	Unit* unit[3];
//
//	unit[0] = new Zillut;
//	unit[1] = new Mutal;
//	unit[2] = new Dropship;
//
//	for (int i = 0; i < 3; i++) {
//		unit[i]->running();
//		unit[i]->flying();
//		unit[i]->burrowing();
//	}
//}