#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Circle : public Shape {
	// 设置基类的构造函数为私有，所以客户端代码不能从这里产生对象，强制使用工厂方法
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