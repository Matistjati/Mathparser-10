#pragma once
#ifndef OPERATOR_H
#define OPERATOR_H
#include <map>

class Operator
{
public:

	const static int add = 0;
	const static int subtract = 1;
	const static int multiply = 2;
	const static int divide = 3;

	static std::map<char, int> operatorPrecedenceS;
	static std::map<int, int> operatorPrecedenceI;
	static std::map<char, int> charToOperator;
	static std::map<int, char> OperatorToChar;


};



#endif
