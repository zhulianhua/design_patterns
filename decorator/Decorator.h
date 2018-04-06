#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

class Decorator : public Beverage {
protected:
	Beverage* beverage;
public:
	// 这里为何需要重新定义getDescription() ?
	Decorator(Beverage* b) : beverage(b) {};
	virtual string getDescription() = 0;
};