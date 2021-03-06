// decorator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Beverage.h"
#include "DarkRoast.h"
#include "Milk.h"
#include "Mocha.h"
#include "Soy.h"
#include "largeCup.h"

using namespace std;



int main()
{
	Beverage* beverage = new DarkRoast();
	beverage = new Milk(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;
	beverage = new Milk(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;
	beverage = new Mocha(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;

	beverage = new LargeCup(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;


	beverage = new LargeCup(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;

	// 为何我们需要一个Decorator类？下面的例子显示即使Soy直接继承自Beverage也可以实现上述功能
	beverage = new Soy(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;

	beverage = new Milk(beverage);
	cout << beverage->getDescription() << endl;
	cout << beverage->cost() << endl;
    return 0;
}

