#define _CRT_SECURE_NO_WARNINGS
#include "Equation.h"
#include <cstdio>
#include <iostream>


void Equation::solve() {

    double D = b * b - 4 * a * c;

    if (D > 0) {
        sol1 = (-b + sqrt(D)) / (2 * a);
        sol2 = (-b - sqrt(D)) / (2 * a);
    }
    else if (D == 0) {
        sol1 = -b / (2 * a);
        sol2 = NAN;
    }
    else {
        sol1 = NAN;
    }   sol2 = NAN;
}

Equation::Equation(std::string str) {
    int result = std::sscanf(str.c_str(), "%lf %lf %lf", &a, &b, &c);
    solve();
    if (result != 3) {
        std::cerr << "Ошибка парсинга: прочитано " << result << " чисел из 3\n";
    }
}