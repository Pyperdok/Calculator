#pragma once
#include <MathParser/IMathFunction/IMathFunction.h>

namespace Calculator {
	class Lg : public IMathFunction {
		public:
			float Calculate(float value) const override;
		};
}
