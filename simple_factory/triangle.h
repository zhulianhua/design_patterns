#pragma once
#include "shape.h"
#include <iostream>
using namespace std;

class Triangle :
	public Shape
{
	Triangle() {};
	friend class Factory;
public:
	void draw() {
		cout << "Triangle::draw()" << endl;
	}
	void erase() {
		cout << "Triangle::erase()" << endl;
	}
};
