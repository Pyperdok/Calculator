#pragma once
#include "Context/AdditionalFunction/AdditionalFunction.h"

using namespace AdditionalFunctionContext;

namespace CalculatorTests {
	TEST_F(MathParserAddFunction, Test1) {
		MathParser* math = new MathParser(param, "exp(6)");
		EXPECT_FLOAT_EQ(math->GetResult(), expf(6));
	}

	TEST_F(MathParserAddFunction, Test2) {
		MathParser* math = new MathParser(param, "exp(0)");
		EXPECT_FLOAT_EQ(math->GetResult(), expf(0));
	}

	TEST_F(MathParserAddFunction, Test3) {
		MathParser* math = new MathParser(param, "exp(-1)");
		EXPECT_FLOAT_EQ(math->GetResult(), expf(-1));
	}

	TEST_F(MathParserAddFunction, Test4) {
		MathParser* math = new MathParser(param, "exp(-1-(sin(-5)))");
		EXPECT_FLOAT_EQ(math->GetResult(), expf(-1-(sinf(-5))));
	}
}