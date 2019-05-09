#include "Operator.h"

std::map<char, int> Operator::operatorPrecedenceS = std::map<char, int>{ {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1} };
std::map<int, int> Operator::operatorPrecedenceI = std::map<int, int>{ {add, 0}, {subtract, 0}, {multiply, 1}, {divide, 1} };
std::map<char, int> Operator::charToOperator = { {'+', Operator::add}, {'-', Operator::subtract}, {'*', Operator::multiply}, {'/', Operator::divide} };
std::map<int, char> Operator::OperatorToChar = { {Operator::add, '+'}, {Operator::subtract, '-'}, {Operator::multiply, '*'}, {Operator::divide, '/'} };

int Operator::GetPrecedence() const
{
	return operatorPrecedenceI[type];
}

Operator::Operator(int type, int index, int parenthesisLevel) : type(type), index(index), parenthesisLevel(parenthesisLevel)
{
}

Operator::Operator()
{
	type = Operator::invalid;
	index = -1;
	parenthesisLevel = -1;
}
