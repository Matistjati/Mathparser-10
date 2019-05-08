#include "ExpressionTree.h"
#include "Operator.h"
#include "Number.h"
#include <iostream>

int charToInt(char c)
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

ExpressionTree::ExpressionTree()
{}

ExpressionTree::ExpressionTree(std::string expression)
{
	int highestPrecedenceIndex = -1;
	int highestPrecedence = -1;
	for (unsigned int i = 0; i < expression.length(); i++)
	{
		char current = expression[i];
		if (Operator::operatorPrecedenceS.count(current))
		{
			if (Operator::operatorPrecedenceS[current] > highestPrecedence)
			{
				highestPrecedenceIndex = i;
				highestPrecedence = Operator::operatorPrecedenceS[expression[i]];
			}
		}

	}

	head = new OperatorNode(Operator::charToOperator[expression[highestPrecedenceIndex]]);

	for (size_t i = highestPrecedenceIndex; i < expression.length(); i++)
	{
		if (charToInt(expression[i]) >= 0)
		{
			head->childRight = new NumberNode(charToInt(expression[i]));
			break;
		}
	}
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
