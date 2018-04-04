#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Square : public Shape {
	// ���û���Ĺ��캯��Ϊ˽�У����Կͻ��˴��벻�ܴ������������ǿ��ʹ�ù�������
	Square() {};
	friend class SquareFactory;
public:
	void draw() {
		cout << "Square::draw()" << endl;
	}
	void erase() {
		cout << "Square::erase()" << endl;
	}
};