#pragma once

namespace Calculator {
    class IBinaryOperator {
        public:
            virtual float Compute(float a, float b) const = 0;
        };
}