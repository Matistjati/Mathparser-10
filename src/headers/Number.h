#pragma once
#ifndef NUMBER_H
#define NUMBER_H
#include <string>

class Number
{
public:
	bool isReal;
	std::string tostring();
	virtual double GetRealPart() = 0;
	virtual double GetImagPart() = 0;
};

class Real : public Number
{
public:
	double value;
	Real();
	Real(double val);
	double GetRealPart() { return value; };
private:
	double GetImagPart() { return 0; };
};

class Complex : public Number
{
public:
	double realPart;
	double imaginaryPart;
};

#endif
