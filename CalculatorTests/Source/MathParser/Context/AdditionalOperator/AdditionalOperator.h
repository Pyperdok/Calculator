#pragma once
#include "gtest/gtest.h"
#include <MathParser/MathParser.h>

using namespace Calculator;

namespace AdditionalOperatorContext {
	class Sqr : public IBinaryOperator {
		public:
			float Compute(float a, float b) const override;
	};

	struct MathParserAddOperator : public testing::Test {
		protected:
			MathParserParam* param;
			void SetUp() override;
			void TearDown() override;
	};
}