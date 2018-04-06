#pragma once
#include <string>
#include "beverage.h"

using namespace std;

class Espresso : public Beverage {
public:
	double cost() { return 0.8; }
	string getDescription() { return "Espresso coffe"; }
	CupSize getCupSize() { return smallCup; }
};