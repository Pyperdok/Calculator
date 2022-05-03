#pragma once
#include <MathParser/IBinaryOperator/BinaryOperator/Sub.h>

using namespace Calculator;

float Sub::Compute(float a, float b) const {
    return a - b;
};