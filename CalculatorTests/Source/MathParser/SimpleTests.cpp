#pragma once
#include "Context/Default.h"

using namespace DefaultContext;

namespace CalculatorTests {
	TEST(MathParserSimple, Test1) {
		MathParser* math = new MathParser(param, "3+5-71-0+4+0+56");
		EXPECT_EQ(math->GetResult(), 3+5-71-0+4+0+56);
	}

	TEST(MathParserSimple, Test2) {
		MathParser* math = new MathParser(param, "3-5");
		EXPECT_EQ(math->GetResult(), 3-5);
	}

	TEST(MathParserSimple, Test3) {
		MathParser* math = new MathParser(param, "0-0");
		MathParser* math2 = new MathParser(param, "0+0");
		EXPECT_EQ(math->GetResult()+math2->GetResult(), 0);
	}

	TEST(MathParserSimple, Test4) {
		MathParser* math = new MathParser(param, "15*0");
		EXPECT_EQ(math->GetResult(), 0);
	}

	TEST(MathParserSimple, Test5) {
		MathParser* math = new MathParser(param, "7*3");
		EXPECT_EQ(math->GetResult(), 7*3);
	}

	TEST(MathParserSimple, Test6) {
		MathParser* math = new MathParser(param, "3*7");
		EXPECT_EQ(math->GetResult(), 3*7);
	}

	TEST(MathParserSimple, Test7) {
		MathParser* math = new MathParser(param, "6*1");
		EXPECT_EQ(math->GetResult(), 6*1);
	}

	TEST(MathParserSimple, Test8) {
		MathParser* math = new MathParser(param, "16/5");
		EXPECT_FLOAT_EQ(math->GetResult(), 16.0/5.0);
	}
}