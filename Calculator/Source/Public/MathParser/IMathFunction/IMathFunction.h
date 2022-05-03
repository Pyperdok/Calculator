#pragma once

namespace Calculator {
	class IMathFunction {
		public:
			virtual float Calculate(float value) const = 0;
		};
}
