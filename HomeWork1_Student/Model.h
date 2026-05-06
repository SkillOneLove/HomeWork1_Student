#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Teacher.h"

class Model {
private:
	Teacher t;

	void readFile(std::vector<std::string>& v, const std::string& fName);
	int readInt();
public:
	Model();

	void showMenu();

	void startModel();

	~Model() = default;
};
