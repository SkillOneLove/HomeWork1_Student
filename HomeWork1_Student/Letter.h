#pragma once
#include <string>
#include "Equation.h"


class Letter
{
private:
	Equation eq;
	double res1;
	double res2;
	std::string name;
public:
	Letter(const Equation& eq, double res1, double res2, const std::string& name) : eq(eq), res1(res1), res2(res2), name(name) {};

	double getRes1() const { return res1; }
	double getRes2() const { return res2; }
	const std::string& getName() const { return name; }
	const Equation& getEq() const { return eq; }

	~Letter() = default;
};