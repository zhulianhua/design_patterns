#pragma once
#include "product.h"
#include "builder.h"
#include <iostream>

using namespace std;

class ContrectBuilderA : public Builder {
public:
	void buildPartA();
	void buildPartB();
	void buildPartC();
};

void ContrectBuilderA::buildPartA() {
	product.setPartA("A red partA ");
}

void ContrectBuilderA::buildPartB() {
	product.setPartB("a large partB ");
}

void ContrectBuilderA::buildPartC() {
	product.setPartC("a long partC");
}