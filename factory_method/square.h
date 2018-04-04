#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Square : public Shape {
	// 设置基类的构造函数为私有，所以客户端代码不能从这里产生对象，强制使用工厂方法
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