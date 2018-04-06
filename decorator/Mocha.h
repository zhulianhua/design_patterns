#pragma once
#include <string>
#include "Decorator.h"
#include "Beverage.h"

class Mocha : public Decorator {
public:
	Mocha(Beverage* b) : Decorator(b) {}
	double cost() {
		return 0.2 + beverage->cost();
	}
	string getDescription() {
		return beverage->getDescription() + " with Mocha";
	}
	CupSize getCupSize() { return beverage->getCupSize(); }
};