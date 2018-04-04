#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Circle : public Shape {
	// ���û���Ĺ��캯��Ϊ˽�У����Կͻ��˴��벻�ܴ������������ǿ��ʹ�ù�������
	Circle() {};
	// ��������Ϊ��friend, ����Shape�ľ�̬�������������������Է����乹�캯����
	// ��ȻҲ����ֻ���Ǹ���������������Ϊ��Ԫ����
	//friend class Shape;
	//friend Shape* Shape::createShape(string str);
	friend class Factory;
public:
	void draw() {
		cout << "Circle::draw()" << endl;
	}
	void erase() {
		cout << "Circle::erase()" << endl;
	}
};
