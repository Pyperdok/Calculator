#pragma once
#include <MathParser/IBinaryOperator/IBinaryOperator.h>

namespace Calculator {
    class Mul : public IBinaryOperator {
        public:
            float Compute(float a, float b) const override;
        };
}