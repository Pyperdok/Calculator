#pragma once
#include <math.h>
#include <MathParser/IMathFunction/MathFunction/Lg.h>

using namespace Calculator;

float Lg::Calculate(float value) const {
	return log10f(value);
}