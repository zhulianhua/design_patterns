#pragma once
#include <iostream>
#include "phone.h"

using namespace std;

class XiaomiPhone : public Phone {
public:
	void showSpec() { cout << "Super long battery (40 hours)!!!" << endl; }
};