#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract Product
class Tv {
public:
	virtual void showUsage() = 0;
};