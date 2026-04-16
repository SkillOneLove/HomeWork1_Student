#pragma once
#include <string>
#include "Equation.h"


class Letter
{
public:
	Equation eq;
	double res1;
	double res2;
	std::string name;

	Letter(Equation& eq, double res1, double res2, const std::string& name) : eq(eq), res1(res1), res2(res2), name(name) {};

	~Letter() = default;
};