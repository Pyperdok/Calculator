#pragma once
#include <map>
#include <list>

#include <MathParser/IBinaryOperator/IBinaryOperator.h>
#include <MathParser/IMathFunction/IMathFunction.h>

namespace Calculator {
	class MathParserParam {
		private:
			std::map<char, std::pair<int, const IBinaryOperator*>> _operators;
			std::map<std::string, const IMathFunction*> _functions;
		public:
			MathParserParam();
			~MathParserParam();

			bool IsBinaryOperator(char op) const;
			bool IsFunction(std::string name) const;

			const IBinaryOperator* GetOperator(char op) const;
			const IMathFunction* GetFunction(std::string name) const;

			int GetOperatorPriority(char op) const;
			std::list<std::string> GetFunctionNames() const;

			void AddOperator(char op, int priority, const IBinaryOperator* binaryOperator);
			void AddFunction(std::string name, const IMathFunction* function);
	};
}