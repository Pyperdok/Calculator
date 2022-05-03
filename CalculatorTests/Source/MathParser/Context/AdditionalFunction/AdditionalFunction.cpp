#pragma once
#include "AdditionalFunction.h"

namespace AdditionalFunctionContext {

	float Exp::Calculate(float value) const {
		return expf(value);
	}

	void MathParserAddFunction::SetUp() {
		param = new MathParserParam();
		param->AddFunction("exp", new Exp());
	}

	void MathParserAddFunction::TearDown() {
		delete param;
	}
}