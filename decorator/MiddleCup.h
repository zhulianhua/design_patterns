#pragma once
#include <string>
#include "Beverage.h"
#include "Decorator.h"

class Middle : public Decorator {
	Beverage* beverage;
public:
	Middle(Beverage* b) : beverage(b) {}
	CupSize getCupSize() { return largeCup; }
	double cost() { return beverage->cost() + 1.0; }
	string getDescription() { return beverage->getDescription() + " with middle cup size"; }
};