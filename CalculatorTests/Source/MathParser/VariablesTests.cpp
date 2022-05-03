#pragma once
#include "Context/Default.h"

using namespace DefaultContext;

namespace CalculatorTests {
	TEST(MathParserVariables, Test1) {
		MathParser* math = new MathParser(param, "30 -10", "X+(Y+30)/20");
		std::cerr << math->GetFormula() << std::endl;
		EXPECT_FLOAT_EQ(math->GetResult(), 30.0+(-10.0+30.0)/20.0);
	}

	TEST(MathParserVariables, Test2) {
		MathParser* math = new MathParser(param, "30 -10 7", "X+(Y+30*Z*Z*Y)");
		EXPECT_FLOAT_EQ(math->GetResult(), 30+(-10+30*7*7*(-10)));
	}

	TEST(MathParserVariables, Test3) {
		MathParser* math = new MathParser(param, "30 -10 7", "sin(X)*cos(Y)*lg(Z)");
		EXPECT_FLOAT_EQ(math->GetResult(), sinf(30) * cosf(-10) * log10f(7));
	}

	TEST(MathParserVariables, Test4) {
		MathParser* math = new MathParser(param, "-30", "-X");
		EXPECT_FLOAT_EQ(math->GetResult(), -(-30));
	}
}