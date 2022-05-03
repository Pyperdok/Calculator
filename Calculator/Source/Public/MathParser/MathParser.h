#pragma once
#include <MathParser/MathParserParam.h>

namespace Calculator {
	class MathParser {
		private:
			const MathParserParam* _param;
			std::string _formula;
			float _result;

			std::list<std::string> Reverse(const std::string& str) const;
		public:
			MathParser(const MathParserParam* param, std::string formula);
			MathParser(const MathParserParam* param, std::string variables, std::string formula);

			std::string GetFormula() const;
			float GetResult() const;

			static std::string Format(std::string variables, std::string formula);
			static bool IsNumber(const std::string& str);
	};
}
