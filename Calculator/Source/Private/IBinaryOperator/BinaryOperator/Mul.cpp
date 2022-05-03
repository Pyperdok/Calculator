#pragma once
#include <MathParser/IBinaryOperator/BinaryOperator/Mul.h>

using namespace Calculator;

float Mul::Compute(float a, float b) const {
    return a * b;
};