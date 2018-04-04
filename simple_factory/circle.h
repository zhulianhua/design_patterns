#pragma once
#include <string>
#include <iostream>
#include "shape.h"
using namespace std;

class Circle : public Shape {
	// 设置基类的构造函数为私有，所以客户端代码不能从这里产生对象，强制使用工厂方法
	Circle() {};
	// 将基类设为其friend, 所以Shape的静态函数（工厂方法）可以访问其构造函数；
	// 当然也可以只把那个工厂方法函数设为友元函数
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
