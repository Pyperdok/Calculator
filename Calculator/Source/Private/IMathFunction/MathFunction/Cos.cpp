#pragma once
#include <math.h>
#include <MathParser/IMathFunction/MathFunction/Cos.h>

using namespace Calculator;

float Cos::Calculate(float value) const {
	return cosf(value);
};