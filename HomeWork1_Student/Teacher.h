#pragma once
#include <map>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include "Equation.h"
#include "Letter.h"
#include "Student.h"

class Teacher
{
private:
	std::map<const std::string, int> log;
	std::vector<Equation> tasks;
	std::vector<Letter> uncheckedTasks;
	std::vector<Student> listStudents;

	std::mt19937 gen{ std::random_device{}() };

public:
	Teacher() = default;

	Teacher(std::map<const std::string, int>& log, std::vector<Equation>& tasks, std::vector<Student>& listStudents) : 
		log(std::move(log)), tasks(std::move(tasks)), listStudents(std::move(listStudents)) {}

	void giveTasks();

	void askToSolve();

	void getResults();

	void checkResults();

	void sendLog();

	size_t countUncheckedLetters() { return uncheckedTasks.size(); }

	~Teacher() = default;
};