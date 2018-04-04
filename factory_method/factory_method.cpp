// factory_method.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "factory.h"
#include "squareFactory.h"
#include "circleFactory.h"

int main()
{
	Factory* fac = new SquareFactory;
	Shape* shape = fac->createShape();
	shape->draw();
	//Shape* newShape = new Circle;
    return 0;
}