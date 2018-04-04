#pragma once
#include "factory.h"
#include "shape.h"
#include "circle.h"

class CircleFactory : public Factory {
	Shape * createShape(){
		return new Circle;
	};
};
