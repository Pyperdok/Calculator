#pragma once
#include <math.h>
#include <MathParser/IMathFunction/MathFunction/Sin.h>

using namespace Calculator;

float Sin::Calculate(float value) const {
	return sinf(value);
}
