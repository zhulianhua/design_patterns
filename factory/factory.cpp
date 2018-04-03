// factory.cpp: 定义控制台应用程序的入口点。
// 工厂方法模式: 强制通过一个工厂方法来创建对象

#include "stdafx.h"

#include <string>
#include <iostream>

using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;

	class BadShapeCreation : public logic_error {
	public:
		// 把工厂方法设计为基类的静态函数
		BadShapeCreation(string str) : logic_error("Error !! Can not create Shape with type " + str) {}
	};

	static Shape* createShape(string str) throw(BadShapeCreation); //这个函数可能抛出的异常，在这里定义
};

class Circle : public Shape {
	// 设置基类的构造函数为私有，所以客户端代码不能从这里产生对象，强制使用工厂方法
	Circle() {};
	// 将基类设为其friend, 所以Shape的静态函数（工厂方法）可以访问其构造函数；
	// 当然也可以只把那个工厂方法函数设为友元函数
	//friend class Shape;
	friend Shape* Shape::createShape(string str);
public:
	void draw() {
		cout << "Circle::draw()" << endl;
	}
	void erase() {
		cout << "Circle::erase()" << endl;
	}
};

class Square : public Shape {
	// 设置基类的构造函数为私有，所以客户端代码不能从这里产生对象，强制使用工厂方法
	Square() {};
	// 将基类设为其friend, 所以Shape的静态函数（工厂方法）可以访问其构造函数
	friend class Shape;
public:
	void draw() {
		cout << "Square::draw()" << endl;
	}
	void erase() {
		cout << "Square::erase()" << endl;
	}
};

Shape * Shape::createShape(string type) throw(BadShapeCreation)
{
	// 简单工厂方法的弊端：每次增加新的代码都需要修改这里（意味着修改基类定义），因为此处是硬编码的
	if (type == "Circle") return new Circle; // 因为派生类的构造函数是私有的，所以需要声明Shape类为派生类的友元类
	if (type == "Square")  return new Square; // 因为派生类的构造函数是私有的，所以需要声明Shape类为派生类的友元类
	throw BadShapeCreation(type);
}

int main()
{
	try {
		Shape* shape = Shape::createShape("circle");
		shape->draw();
	}
	catch (Shape::BadShapeCreation e) {
		cout << e.what() << endl;
	}

	// can not access
	// Circle cq;

	return 0;
}