#pragma once
#include <string>
#include "Beverage.h"
#include "Decorator.h"

class LargeCup : public Decorator {
	Beverage* beverage;
public:
	LargeCup(Beverage* b) : beverage(b) {}
	CupSize getCupSize() { return largeCup; }
	double cost() { return beverage->cost() + 1.5; }
	string getDescription() { return beverage->getDescription() + " with large cup size"; }
};