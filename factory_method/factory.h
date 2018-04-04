#pragma once
#include <string>
#include "stdafx.h"
#include "shape.h"
using namespace std;

class Factory {
	//Factory() {};
public:
	virtual Shape * createShape()  = 0;
};