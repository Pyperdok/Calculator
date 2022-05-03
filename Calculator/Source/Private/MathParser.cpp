#pragma once
#include <regex>
#include <stack>

#include <MathParser/MathParser.h>

using namespace Calculator;

using std::string;
using std::map;
using std::list;
using std::stack;
using std::remove_if;
using std::replace;
using std::vector;
using std::regex;

MathParser::MathParser(const MathParserParam* param, string formula) : _param(param) {
	formula.erase(remove_if(formula.begin(), formula.end(), isspace), formula.end()); //???????
	_formula = regex_replace(formula, regex("\\(-"), "(0-"); //???????
}

MathParser::MathParser(const MathParserParam* param, string variables, string formula) : _param(param) {
	formula.erase(remove_if(formula.begin(), formula.end(), isspace), formula.end()); //???????
	_formula = Format(variables, formula);
	_formula = regex_replace(_formula, regex("\\(-"), "(0-"); //??????
}

float MathParser::GetResult() const {
	list<string> reversed = Reverse(_formula);
	stack<float> stack;
	for (string token : reversed) {
		float result;
		if (IsNumber(token)) {
			result = stof(token);
		}
		if (_param->IsBinaryOperator(token[0])) {
			float b = 0;
			if (stack.size()) { //???????
				b = stack.top();
				stack.pop();
			}
			float a = 0;
			if (stack.size()) { //???????
				a = stack.top();
				stack.pop();
			}
			result = _param->GetOperator(token[0])->Compute(a, b);
		}
		if (_param->IsFunction(token)) {
			float x = stack.top();
			stack.pop();
			result = _param->GetFunction(token)->Calculate(x);
		}
		stack.push(result);
	}
	return stack.top();
}

list<string> MathParser::Reverse(const string& str) const { //Algorithm of sorting station (Expression -> Reverse Notation)
	stack<string> operators;
	list<string> functions = _param->GetFunctionNames();
	list<string> result;

	for (int i = 0; i < (int)str.length(); i++) {
		int k = i;
		while (isdigit(str[k])) {
			k++;
		}
		if (i != k) {
			result.push_back(str.substr(i, k - i));
			i = k;
		}
		if (_param->IsBinaryOperator(str[i])) {
			while (operators.size() && _param->GetOperatorPriority(str[i]) <= _param->GetOperatorPriority(operators.top().c_str()[0])) { //???????
				result.push_back(operators.top());
				operators.pop();
			}
			operators.push(string(1, str[i]));
		}
		if (str[i] == '(') {
			operators.push(string(1, str[i]));
		}
		if (str[i] == ')') {
			while (operators.size() && operators.top() != "(") {
				result.push_back(operators.top());
				operators.pop();
			}
			operators.pop();
			if (operators.size() && _param->IsFunction(operators.top())) {
				result.push_back(operators.top());
				operators.pop();
			}
		}
		for (auto function : functions) {
			if (str.find(function) == i) {
				operators.push(function);
			}
		}
	}

	while (operators.size()) {
		result.push_back(operators.top());
		operators.pop();
	}
	return result;
}

string MathParser::GetFormula() const {
	return _formula;
}

string MathParser::Format(string variables, string formula) {
	string delimiter = " ";
	size_t pos = 0;
	vector<string> values;
	string token;
	while ((pos = variables.find(delimiter)) != string::npos) {
		string token = variables.substr(0, pos);
		values.push_back(token);
		variables.erase(0, pos + delimiter.length());
	}
	values.push_back(variables);

	string name[] = { "X", "Y", "Z" };
	for (int i = 0; i < (int)values.size(); i++) {
		formula = regex_replace(formula, regex(name[i]), "("+values[i]+")");
	}

	return formula;
}

bool MathParser::IsNumber(const string& str) {
	bool result = false;
	for (char const& c : str) {
		if (isdigit(c)) {
			result = true;
			break;
		}
	}
	return result;
}
