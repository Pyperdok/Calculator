#pragma once
#include "AdditionalOperator.h"

namespace AdditionalOperatorContext {

	float Sqr::Compute(float a, float b) const {
		return powf(a, b);
	}

	void MathParserAddOperator::SetUp() {
		param = new MathParserParam();
		param->AddOperator('^', 3, new Sqr());
	}

	void MathParserAddOperator::TearDown() {
		delete param;
	}
}