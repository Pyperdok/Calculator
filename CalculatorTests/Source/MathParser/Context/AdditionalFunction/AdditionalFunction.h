#pragma once
#include "gtest/gtest.h"
#include <MathParser/MathParser.h>

using namespace Calculator;

namespace AdditionalFunctionContext {
	class Exp : public IMathFunction {
		public:
			float Calculate(float value) const override;
	};

	struct MathParserAddFunction : public testing::Test {
		protected:
			MathParserParam* param;
			void SetUp() override;
			void TearDown() override;
	};
}