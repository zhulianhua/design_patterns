#pragma once
#include "factory.h"
#include "shape.h"
#include "square.h"

class SquareFactory : public Factory {
public:
	Shape * createShape() { return new Square; }
};