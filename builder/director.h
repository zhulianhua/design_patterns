#pragma once
#include "builder.h"

class Director {
	Builder * builder;
public:
	// ָ���������̲���װ�������õ�������Ʒ
	Product* construct() {
		builder->buildPartA();
		builder->buildPartB();
		builder->buildPartC();
		return builder->getResult();
	};
	// �������þ���ʹ���ĸ�Builder
	void setBuilder(Builder* b) {
		builder = b;
	};
};	