#pragma once
#include <string>

using namespace std;

class Beverage {
protected:
	string description;
public:
	enum CupSize {smallCup, middleCup, largeCup};
	virtual double cost() = 0;
	virtual string getDescription() = 0;
	virtual CupSize getCupSize() = 0;
};