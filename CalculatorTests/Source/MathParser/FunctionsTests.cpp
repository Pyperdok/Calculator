#pragma once
#include "Context/Default.h"
#include <MathParser/MathParser.h>

using namespace DefaultContext;

namespace CalculatorTests {
	TEST(MathParserFunctions, Test1) {
		MathParser* math = new MathParser(param, "lg(100)*5");
		EXPECT_FLOAT_EQ(math->GetResult(), log10(100)*5);
	}

	TEST(MathParserFunctions, Test2) {
		MathParser* math = new MathParser(param, "sin(0)");
		EXPECT_EQ(math->GetResult(), sinf(0));
	}

	TEST(MathParserFunctions, Test3) {
		MathParser* math = new MathParser(param, "sin(1)");
		EXPECT_EQ(math->GetResult(), sinf(1));
	}

	TEST(MathParserFunctions, Test4) {
		MathParser* math = new MathParser(param, "cos(0)");
		EXPECT_EQ(math->GetResult(), cosf(0));
	}

	TEST(MathParserFunctions, Test5) {
		MathParser* math = new MathParser(param, "cos(1)");
		EXPECT_EQ(math->GetResult(), cosf(1));
	}

	TEST(MathParserFunctions, Test6) {
		MathParser* math = new MathParser(param, "sin((4*3)/9)");
		EXPECT_EQ(math->GetResult(), sinf((4 * 3) / 9.0));
	}
}