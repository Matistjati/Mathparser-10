#pragma once
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include "Operator.h"
#include "Number.h"

class Node;

class Node
{
public:
	bool isOperator;
	Node *childLeft;
	Node *childRight;
	virtual int GetOperator() = 0;
	virtual double GetRealPart() = 0;
	virtual double GetImagPart() = 0;
};

class OperatorNode : public Node
{
public:
	int operatorIndex;
	OperatorNode();
	OperatorNode(int OperatorIndex);
	int GetOperator();
private:
	double GetRealPart() { return 0; };
	double GetImagPart() { return 0; };
};

class NumberNode : public Node
{
public:
	Number *nodeNumber;
	NumberNode();
	NumberNode(double number);
	NumberNode(double real, double imaginary );
	
	double GetRealPart() { return nodeNumber->GetRealPart(); };
	double GetImagPart() { return nodeNumber->GetImagPart(); };
private:
	int GetOperator() { return -1; };
};


class ExpressionTree
{
public:
	Node *head;
	ExpressionTree();
	ExpressionTree(std::string source);
	std::string tostring();
};

#endif
