#pragma once
#include <iostream>
#include "phone.h"

using namespace std;

class HuaweiPhone : public Phone {
public:
	void showSpec() { cout << "Powered by Kylin CPU and Lecia Lens" << endl; }
};