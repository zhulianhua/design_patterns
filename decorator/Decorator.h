#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

class Decorator : public Beverage {
protected:
	Beverage* beverage;
public:
	// ����Ϊ����Ҫ���¶���getDescription() ?
	Decorator(Beverage* b) : beverage(b) {};
	virtual string getDescription() = 0;
};