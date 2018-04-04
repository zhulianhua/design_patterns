#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract Product
class Phone {
public:
	virtual void showSpec() = 0;
};