#include <iostream>
#include <string>
#include "ExpressionTree.h"

const std::string keywords[] = { "plot", "evaluate" };
enum Keyword
{
	bad = 0,
	plot = 1,
	eval = 2,
};
std::map<std::string, Keyword> stringToKeyword = { {"plot", Keyword::plot}, {"evaluate", Keyword::eval } };

bool stringEqualsNoCase(const std::string& a, const std::string& b)
{
	return std::equal(a.begin(), a.end(),
		b.begin(), b.end(),
		[](char a, char b) 
		{
			return tolower(a) == tolower(b);
		}
	);
}

int main()
{
	std::cout << "Enter an expression" << std::endl;
	std::string expression;
    std::getline(std::cin, expression);

	Keyword keyword;

	int indexToFirstSpace = -1;
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ')
		{
			indexToFirstSpace = i;
			break;
		}
	}

	if (indexToFirstSpace != -1)
	{
		int length = (sizeof(keywords) / sizeof((keywords)[0]));
		std::string keyWord = expression.substr(0, indexToFirstSpace);
		for (int i = 0; i < length; i++)
		{
			if (stringEqualsNoCase(keyWord, keywords[i]))
			{
				keyword = stringToKeyword[keyWord];
				break;
			}
		}
		keyword = Keyword::bad;
	}
	else
	{
		keyword = Keyword::eval;
	}


	if (keyword == Keyword::eval)
	{
		ExpressionTree tree;
		if (indexToFirstSpace == -1)
		{
			tree = ExpressionTree(expression);
		}
		else
		{
			tree = ExpressionTree(expression.substr(indexToFirstSpace, expression.npos));
		}

		std::cout << tree.tostring();
	}
	else if (keyword == Keyword::bad)
	{
		std::cout << "Unknown command \"" << expression.substr(0, indexToFirstSpace) << "\"" << std::endl;
#if _debug
		std::cout << "Result from bad keyword";
#endif
	}
	else
	{
		std::cout << "Unknown command \"" << expression.substr(0, indexToFirstSpace) << "\"" << std::endl;
#if _debug
		std::cout << "Result from reaching default else";
#endif
	}
}