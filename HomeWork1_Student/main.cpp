#include <stdlib.h>
#include <iostream>
#include "MathExamModel.h"



int main(void) {
	Teacher teacher = SetupModel();

	StartModel(teacher);
	return 0;
}