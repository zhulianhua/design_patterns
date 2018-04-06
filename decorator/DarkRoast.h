#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

class DarkRoast : public Beverage {
public:
	double cost() { return 0.9; }
	string getDescription() { return "DarkRoast coffe"; }
	CupSize getCupSize() { return smallCup; }
};