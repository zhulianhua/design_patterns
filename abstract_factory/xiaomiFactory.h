#pragma once
#pragma once
#include "factory.h"
#include "xiaomiPhone.h"
#include "xiaomiTv.h"

class XiaomiFactory : public Factory {
public:
	Phone * createPhone() { return new XiaomiPhone(); }
	Tv* createTv() { return new XiaomiTv(); }
};