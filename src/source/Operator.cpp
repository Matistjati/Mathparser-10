#include "Operator.h"

std::map<char, int> Operator::operatorPrecedenceS = std::map<char, int>{ {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1} };
std::map<int, int> Operator::operatorPrecedenceI = std::map<int, int>{ {add, 0}, {subtract, 0}, {multiply, 1}, {divide, 1} };
std::map<char, int> Operator::charToOperator = { {'+', Operator::add}, {'-', Operator::subtract}, {'*', Operator::multiply}, {'/', Operator::divide} };
std::map<int, char> Operator::OperatorToChar = { {Operator::add, '+'}, {Operator::subtract, '-'}, {Operator::multiply, '*'}, {Operator::divide, '/'} };