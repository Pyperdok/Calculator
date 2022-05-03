#pragma once
#include <MathParser/IBinaryOperator/BinaryOperator/Add.h>

using namespace Calculator;

float Add::Compute(float a, float b) const {
    return a + b;
};