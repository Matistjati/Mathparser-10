#include "ExpressionTree.h"
#include "Operator.h"
#include "Number.h"
#include <iostream>
#include <vector>
#include <algorithm>

int ExpressionTree::charToInt(char c) const
{
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return -1;
	}
}

int ExpressionTree::countOperators(const std::string & expression) const
{
	int operatorCount = 0;
	for (unsigned int i = 0; i < expression.length(); i++)
	{
		if (Operator::charToOperator.count(expression[i]))
		{
			operatorCount++;
		}
	}
	return operatorCount;
}

ExpressionTree::ExpressionTree()
{}

ExpressionTree::ExpressionTree(const std::string& expression)
{
	std::vector<Operator> operators(0);

	int parenthesisLevel = 0;
	for (unsigned int i = 0; i < expression.length(); i++)
	{
		char current = expression[i];

		if (current == '(')
		{
			parenthesisLevel++;

		}
		else if (current == ')')
		{
			parenthesisLevel--;
		}
		else if (Operator::operatorPrecedenceS.count(current))
		{
			operators.push_back(Operator(Operator::charToOperator[expression[i]], i, parenthesisLevel));
		}
	}

	std::sort(operators.begin(), operators.end(), [](const Operator& left, const Operator& right) {
		return left.GetPrecedence() < right.GetPrecedence();
	});

	std::sort(operators.begin(), operators.end(), [](const Operator& left, const Operator& right) {
		return left.parenthesisLevel < right.parenthesisLevel;
	});

	//head = new OperatorNode(Operator::charToOperator[expression[highestPrecedenceIndex]]);

	if (parenthesisLevel != 0)
	{
		std::cout << "Not all parenthesies were closed. Answer might not be correct" << std::endl;
	}


	/*if (highestPrecedenceIndex + 1 >= expression.length())
	{
		throw std::exception("Operator without number");
	}

	bool foundNumber = false;
	for (size_t i = highestPrecedenceIndex + 1; i < expression.length(); i++)
	{
		if (Operator::charToOperator.count(expression[i]))
		{
			throw std::exception("Two operators cannot follow one another");
		}

		if (charToInt(expression[i]) >= 0)
		{
			head->childRight = new NumberNode(charToInt(expression[i]));
			foundNumber = true;
			break;
		}
	}



	if (highestPrecedenceIndex - 1 < 0)
	{
		throw std::exception("Operator without number");
	}

	foundNumber = false;
	for (size_t i = highestPrecedenceIndex - 1; i >= 0; i--)
	{
		if (charToInt(expression[i]) >= 0)
		{
			head->childLeft = new NumberNode(charToInt(expression[i]));
			foundNumber = true;
			break;
		}
	}*/

}

std::string ExpressionTree::tostring()
{
	if (this->head->isOperator)
	{
		return std::string(1, Operator::OperatorToChar[head->GetOperator()]);
	}
	// TODO: Proper
}

OperatorNode::OperatorNode()
{
	isOperator = true;
}

OperatorNode::OperatorNode(int OperatorIndex)
{
	isOperator = true;
	operatorIndex = OperatorIndex;
}

int OperatorNode::GetOperator()
{
	return operatorIndex;
}

NumberNode::NumberNode()
{
	isOperator = false;
}

NumberNode::NumberNode(double number)
{
	nodeNumber = new Real(number);
}

NumberNode::NumberNode(double real, double imaginary)
{
}
