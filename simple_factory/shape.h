#pragma once
#include <string>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;

	// 把工厂方法设计为基类的静态函数，还有的简单工厂模式专门做一个工厂类，提供工厂方法创建对象(上面的Factory类)
	//class BadShapeCreation : public logic_error {
	//public:
	//	BadShapeCreation(string str) : logic_error("Error !! Can not create Shape with type " + str) {};
	//};
	//static Shape* createShape(string str) throw(BadShapeCreation); //这个函数可能抛出的异常，在这里定义
};