#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

class Decorator : public Beverage {
public:
	// 这里为何需要重新定义getDescription() ?
	virtual string getDescription() = 0;
};