#pragma once
#include <iostream>
#include "Tv.h"

using namespace std;

class HuaweiTv : public Tv {
public:
	void showUsage() { cout << "To use Huawei TV, buy a Net-TV-box first!" << endl; }
};