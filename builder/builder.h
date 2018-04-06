#pragma once
#include "product.h"
// abstract builder
// Builderֻ������������������װ��Director����
class Builder {
protected:
	Product product;
public:
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;

	Product* getResult() { return &product; };
};