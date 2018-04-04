#pragma once
#include <string>

#include "shape.h"
// 每次引入新的派生类都需要修改这里
#include "square.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

class Factory {
	Factory() {};
public:
	class BadShapeCreation : public logic_error {
	public:
		BadShapeCreation(string str) : logic_error("Error !! Can not create Shape with type " + str) {};
	};
	static Shape * createShape(string type) throw(BadShapeCreation);
};

Shape * Factory::createShape(string type) throw(BadShapeCreation) {
	{
		// 每次引入新的派生类都需要修改这里的逻辑
		if (type == "Circle") return new Circle; // 因为派生类的构造函数是私有的，所以需要声明Factory类为派生类的友元类
		if (type == "Square")  return new Square; // 因为派生类的构造函数是私有的，所以需要声明Factory类为派生类的友元类
		if (type == "Triangle")  return new Triangle;
		throw BadShapeCreation(type);
	}
}