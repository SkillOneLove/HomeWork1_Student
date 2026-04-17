#define _CRT_SECURE_NO_WARNINGS
#include "Equation.h"
#include <cstdio>
#include <iostream>


void Equation::solve() {

    // Проверка на линейность
    if (a == 0) {
        // Проверка на вырожденность
        if (b == 0) {
            root1 = NAN;
        }
        else {
            root1 = -c / b;
        }
        root2 = NAN;
        return;
    }

    double D = b * b - 4 * a * c;

    if (D > 0) {
        root1 = (-b + sqrt(D)) / (2 * a);
        root2 = (-b - sqrt(D)) / (2 * a);
    }
    else if (D == 0) {
        root1 = -b / (2 * a);
        root2 = NAN;
    }
    else {
        root1 = NAN;
    }   root2 = NAN;
}

Equation::Equation(std::string str) {
    int result = std::sscanf(str.c_str(), "%lf %lf %lf", &a, &b, &c);
    solve();
    if (result != 3) {
        std::cerr << "Ошибка парсинга: прочитано " << result << " чисел из 3\n";
    }
}