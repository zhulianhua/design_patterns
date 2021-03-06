//// simple_factory.cpp: 定义控制台应用程序的入口点。
//// 简单工厂模式: 强制通过一个工厂方法来创建对象
//// 工厂模式共有三种：简单工厂，工厂方法，抽象工厂
//// 
//
#include "stdafx.h"
#include <iostream>
#include "factory.h"

using namespace std;

int main()
{
	try {
		Shape* s = Factory::createShape("Circle");
		s->draw();
		
		s = Factory::createShape("Square");
		s->erase();
	}
	catch (Factory::BadShapeCreation e) {
		cout << e.what() << endl;
	}
	return 0;
}