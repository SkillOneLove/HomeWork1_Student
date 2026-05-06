#include "Student.h"

Student::Student(const std::string& str) {
    name = str;
    setRandomType();
}

void Student::setRandomType() {
    std::uniform_int_distribution<int> dist(0, 2);
    int t = dist(gen);
    switch (t) {
    case 0: {
        type = GOOD;
        break;
    }
    case 1: {
        type = AVERAGE;
        break;
    }
    case 2: {
        type = BAD;
        break;
    }
    }
}

void Student::solve() {
    double a, b, c;
    a = eq.getA();
    b = eq.getB();
    c = eq.getC();

    // Checking for linearity
    if (a == 0) {
        // Checking for degeneracy
        if (b == 0) {
            myAns1 = NAN;
        }
        else {
            myAns1 = -c / b;
        }
        myAns2 = NAN;
        return; 
    }

    double D = b * b - 4 * a * c;

    if (D > 0) {
        myAns1 = (-b + sqrt(D)) / (2 * a);
        myAns2 = (-b - sqrt(D)) / (2 * a);
    }
    else if (D == 0) {
        myAns1 = -b / (2 * a);
        myAns2 = NAN;
    }
    else {
        myAns1 = NAN;
    }   myAns2 = NAN;
}

void Student::solveEq() {
    solve();
    switch (type) {
    case AVERAGE: {
        std::uniform_int_distribution<int> dist(0, 100);
        if (dist(gen) < 40) {
            if (!std::isnan(myAns1)) {
                myAns1 += 5;
            }
            if (!std::isnan(myAns2)) {
                myAns2 += 5;
            }
        }
        break;
    }
    case BAD: {
        myAns1 = 0;
        myAns2 = 0;
        break;
    }
    }
}

void Student::getEq(Equation& task) {
	eq = task;
}

Letter Student::sendResult() {
    return Letter(eq, myAns1, myAns2, name);
}