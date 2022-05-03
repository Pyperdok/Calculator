#pragma once
#include "Context/Default.h"

using namespace DefaultContext;

namespace CalculatorTests {
	TEST(MathParserPriorities, Test1) {
		MathParser* math = new MathParser(param, "3+5*6");
		EXPECT_EQ(math->GetResult(), 3+5*6);
	}

	TEST(MathParserPriorities, Test2) {
		MathParser* math = new MathParser(param, "(3+5)*6");
		EXPECT_EQ(math->GetResult(), (3+5)*6);
	}

	TEST(MathParserPriorities, Test3) {
		MathParser* math = new MathParser(param, "(3+5)*6/8");
		EXPECT_EQ(math->GetResult(), (3+5)*6/8);
	}

	TEST(MathParserPriorities, Test4) {
		MathParser* math = new MathParser(param, "-(3+17-7)");
		EXPECT_EQ(math->GetResult(), -(3+17-7));
	}

	TEST(MathParserPriorities, Test5) {
		MathParser* math = new MathParser(param, "(3+17-7)");
		EXPECT_EQ(math->GetResult(), (3+17-7));
	}

	TEST(MathParserPriorities, Test6) {
		MathParser* math = new MathParser(param, "7/8*(1-4)");
		EXPECT_EQ(math->GetResult(), 7.0/8.0 *(1.0 -4.0));
	}

	TEST(MathParserPriorities, Test7) {
		MathParser* math = new MathParser(param, "(3+4)*(5/7/6/18)");
		EXPECT_FLOAT_EQ(math->GetResult(), (3.0+4.0)*(5.0/7.0/6.0/18.0));
	}

	TEST(MathParserPriorities, Test8) {
		MathParser* math = new MathParser(param, "(3+4)/(5*7/6*18)");
		EXPECT_FLOAT_EQ(math->GetResult(), (3.0+4.0)/(5.0 *7.0 /6.0 *18.0));
	}

	TEST(MathParserPriorities, Test9) {
		MathParser* math = new MathParser(param, "13-(-77-(-10*5*(-1)))");
		EXPECT_EQ(math->GetResult(), 13-(-77-(-10*5*(-1))));
	}
}