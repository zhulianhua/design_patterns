#pragma once
#include "phone.h"
#include "tv.h"

class Factory {
public:
	virtual Phone* createPhone() = 0;
	virtual Tv* createTv() = 0;
};