#pragma once
#include <iostream>
#include "Tv.h"
using namespace std;

class XiaomiTv : public Tv {
public:
	void showUsage() { cout << "Just press on on/off button" << endl; }
};