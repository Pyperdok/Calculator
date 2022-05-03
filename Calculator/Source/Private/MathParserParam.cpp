#pragma once
#include <string>

#include <MathParser/IBinaryOperator/BinaryOperator/Add.h>
#include <MathParser/IBinaryOperator/BinaryOperator/Sub.h>
#include <MathParser/IBinaryOperator/BinaryOperator/Mul.h>
#include <MathParser/IBinaryOperator/BinaryOperator/Div.h>

#include <MathParser/IMathFunction/MathFunction/Cos.h>
#include <MathParser/IMathFunction/MathFunction/Sin.h>
#include <MathParser/IMathFunction/MathFunction/Lg.h>

#include <MathParser/MathParserParam.h>

using namespace Calculator;

using std::map;
using std::pair;
using std::string;
using std::list;

MathParserParam::MathParserParam() {
	_operators = {
		{'+', {0, new Add()}},
		{'-', {0, new Sub()}},
		{'*', {1, new Mul()}},
		{'/', {1, new Div()}}
	};
	_functions = {
		{"sin", new Sin()},
		{"cos", new Cos()},
		{"lg",  new Lg()}
	};
}

MathParserParam::~MathParserParam() {
	for (auto op : _operators) {
		delete op.second.second;
	}
	for (auto fun : _functions) {
		delete fun.second;
	}
}

bool MathParserParam::IsBinaryOperator(char op) const {
	return _operators.contains(op);
}

bool MathParserParam::IsFunction(string name) const {
	return _functions.contains(name);
}

int MathParserParam::GetOperatorPriority(char op) const {
	int priority = -1;
	if (_operators.contains(op)) {
		priority = _operators.at(op).first;
	}
	return priority;
}

const IBinaryOperator* MathParserParam::GetOperator(char op) const {
	return _operators.at(op).second;
}

const IMathFunction* MathParserParam::GetFunction(string name) const {
	return _functions.at(name);
}

list<string> MathParserParam::GetFunctionNames() const {
	list<string> result;
	for (auto pair : _functions) {
		result.push_back(pair.first);
	}
	return result;
}

void MathParserParam::AddOperator(char op, int priority, const IBinaryOperator* binaryOperator) {
	pair<int, const IBinaryOperator*> priorityOperator(priority, binaryOperator);
	_operators.insert({ op, priorityOperator });
}

void MathParserParam::AddFunction(string name, const IMathFunction* function) {
	_functions.insert({ name, function });
}