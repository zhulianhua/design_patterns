#pragma once
#include <string>

#include "shape.h"
// ÿ�������µ������඼��Ҫ�޸�����
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
		// ÿ�������µ������඼��Ҫ�޸�������߼�
		if (type == "Circle") return new Circle; // ��Ϊ������Ĺ��캯����˽�еģ�������Ҫ����Factory��Ϊ���������Ԫ��
		if (type == "Square")  return new Square; // ��Ϊ������Ĺ��캯����˽�еģ�������Ҫ����Factory��Ϊ���������Ԫ��
		if (type == "Triangle")  return new Triangle;
		throw BadShapeCreation(type);
	}
}