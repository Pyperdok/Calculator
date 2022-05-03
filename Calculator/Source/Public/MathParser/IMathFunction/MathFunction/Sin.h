#pragma once
#include <MathParser/IMathFunction/IMathFunction.h>

namespace Calculator {
	class Sin : public IMathFunction {
		public:
			float Calculate(float value) const override;
		};
}
