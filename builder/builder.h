#pragma once
#include "product.h"
// abstract builder
// Builder只负责生产部件，而组装由Director负责
class Builder {
protected:
	Product product;
public:
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;

	Product* getResult() { return &product; };
};