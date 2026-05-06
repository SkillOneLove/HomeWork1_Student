#pragma once
#include <string>
#include <random>
#include "Type.h"
#include "Equation.h"
#include "Letter.h"

class Student
{
private:
	std::string name;
	Type type;
	Equation eq;

	double myAns1;
	double myAns2;

	std::mt19937 gen{ (std::random_device{}()) };

	void setRandomType();
	void solve();
public:
	Student(const std::string& str);

	void getEq(Equation& task);

	void solveEq();

	Letter sendResult();

	~Student() = default;
};
