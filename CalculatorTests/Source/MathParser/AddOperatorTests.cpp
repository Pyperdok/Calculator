#pragma once
#include "Context/AdditionalOperator/AdditionalOperator.h"

using namespace AdditionalOperatorContext;

namespace CalculatorTests {
	TEST_F(MathParserAddOperator, Test1) {
		MathParser* math = new MathParser(param, "3^5");
		EXPECT_EQ(math->GetResult(), powf(3, 5));
	}

	TEST_F(MathParserAddOperator, Test2) {
		MathParser* math = new MathParser(param, "3^0");
		EXPECT_EQ(math->GetResult(), powf(3, 0));
	}

	TEST_F(MathParserAddOperator, Test3) {
		MathParser* math = new MathParser(param, "3^(-1)");
		EXPECT_FLOAT_EQ(math->GetResult(), powf(3, -1));
	}

	TEST_F(MathParserAddOperator, Test4) {
		MathParser* math = new MathParser(param, "0^0");
		std::cerr << powf(0, 0) << std::endl;
		EXPECT_FLOAT_EQ(math->GetResult(), powf(0, 0));
	}
}