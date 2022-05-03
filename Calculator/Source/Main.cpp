#pragma once
#include <iostream>
#include <sstream>

#include <MathParser/MathParser.h>

using namespace std;
using namespace Calculator;

int main(int argc, char* argv[]) {

	MathParserParam* param = new MathParserParam();

	string expression = string(argv[1]);
	string vars = "";
	
	getline(cin, vars);

	MathParser* math = new MathParser(param, vars, expression);
	cout << math->GetResult() << endl;

	return 0;
}