#pragma once
#include <string>

class Equation
{
private:
	void solve();
public:
	double a;
	double b;
	double c;

	double sol1;
	double sol2;

	Equation() = default;
	Equation(std::string str);

	~Equation() = default;
};