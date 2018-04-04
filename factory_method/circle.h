#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Circle : public Shape {
	// ���û���Ĺ��캯��Ϊ˽�У����Կͻ��˴��벻�ܴ������������ǿ��ʹ�ù�������
	Circle() {};
	friend class CircleFactory;
public:
	void draw() {
		cout << "Circle::draw()" << endl;
	}
	void erase() {
		cout << "Circle::erase()" << endl;
	}
};