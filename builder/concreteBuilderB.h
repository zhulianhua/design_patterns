#pragma once
#include "product.h"
#include "builder.h"
#include <iostream>

using namespace std;

class ContrectBuilderB : public Builder {
public:
	void buildPartA();
	void buildPartB();
	void buildPartC();
};

void ContrectBuilderB::buildPartA() {
	product.setPartA("A blue partA ");
}

void ContrectBuilderB::buildPartB() {
	product.setPartB("a small partB ");
}

void ContrectBuilderB::buildPartC() {
	product.setPartC("a short partC ");
}