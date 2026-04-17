#pragma once
#include <string>

class Equation
{
private:
	double a;
	double b;
	double c;

	double root1;
	double root2;

	void solve();	// Used only in the constructor
public:

	Equation() = default;
	Equation(std::string str);

	double getA()     const { return a; }
	double getB()     const { return b; }
	double getC()     const { return c; }
	double getRoot1() const { return root1; }
	double getRoot2() const { return root2; }

	~Equation() = default;
};