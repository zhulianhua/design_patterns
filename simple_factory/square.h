#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Square : public Shape {
	// ���û���Ĺ��캯��Ϊ˽�У����Կͻ��˴��벻�ܴ������������ǿ��ʹ�ù�������
	Square() {};
	// ��������Ϊ��friend, ����Shape�ľ�̬�������������������Է����乹�캯��
	// friend class Shape;
	friend class Factory;
public:
	void draw() {
		cout << "Square::draw()" << endl;
	}
	void erase() {
		cout << "Square::erase()" << endl;
	}
};
