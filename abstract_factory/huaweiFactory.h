#pragma once
#include "factory.h"
#include "huaweiPhone.h"
#include "huaweiTv.h"

class HuaweiFactory : public Factory {
public:
	Phone* createPhone() { return new HuaweiPhone(); }
	Tv* createTv() { return new HuaweiTv(); }
};