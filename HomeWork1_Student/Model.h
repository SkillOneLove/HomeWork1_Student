#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Teacher.h"

class Model {
private:
	Teacher t;

public:
	Model();

	void startModel();

	~Model() = default;
};
