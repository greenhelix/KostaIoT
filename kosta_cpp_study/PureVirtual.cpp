#include <stdio.h>

class Shape {
public:
	virtual void draw() = 0;
};

class Line : public Shape {
public: 
	virtual void draw() { puts("line drawing"); }
};

class Circle : public Shape {
public:
	virtual void draw() { puts("circle drawing"); }
};

class Rect : public Shape {
public:
	virtual void draw() { puts("rect drawing"); }
};

//int main() {
//	Shape* ps[3];
//
//	ps[0] = new Line;
//	ps[1] = new Circle;
//	ps[2] = new Rect;
//
//	for (int i = 0; i < 3; i++)
//	{
//		ps[i]->draw();
//	}
//
//	for (int i = 0; i < 3; i++) {
//		delete ps[i];
//	}
//}