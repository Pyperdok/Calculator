#pragma once
#include <MathParser/IBinaryOperator/IBinaryOperator.h>

namespace Calculator {
    class Add : public IBinaryOperator {
        public:
            float Compute(float a, float b) const override;
        };
}