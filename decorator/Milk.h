#pragma once
#pragma once
#include <string>
#include "Decorator.h"
#include "Beverage.h"

class Milk : public Decorator {
public:
	Milk(Beverage* b) : Decorator(b) { }
	double cost() {
		return 0.1 + beverage->cost();
	}
	string getDescription() {
		return beverage->getDescription() + " with Milk";
	}
	CupSize getCupSize() { return beverage->getCupSize(); }
};