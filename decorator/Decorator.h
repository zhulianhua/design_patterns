#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

class Decorator : public Beverage {
public:
	// ����Ϊ����Ҫ���¶���getDescription() ?
	virtual string getDescription() = 0;
};