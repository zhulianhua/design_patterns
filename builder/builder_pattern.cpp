// builder.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "director.h"
#include "product.h"
#include "concreteBuilderA.h"
#include "concreteBuilderB.h"

int main()
{
	Director director;
	Builder* builder = new ContrectBuilderA();
	director.setBuilder(builder);
	Product* product = director.construct();
	product->whatInside();

	builder = new ContrectBuilderB();
	director.setBuilder(builder);
	product = director.construct();
	product->whatInside();
	return 0;
}