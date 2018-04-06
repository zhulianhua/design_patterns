#pragma once
#include "builder.h"

class Director {
	Builder * builder;
public:
	// 指挥生产过程并组装部件，得到完整产品
	Product* construct() {
		builder->buildPartA();
		builder->buildPartB();
		builder->buildPartC();
		return builder->getResult();
	};
	// 可以设置具体使用哪个Builder
	void setBuilder(Builder* b) {
		builder = b;
	};
};	