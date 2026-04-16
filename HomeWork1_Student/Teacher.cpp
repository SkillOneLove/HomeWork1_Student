#include "Teacher.h"

void Teacher::giveTasks() {
    std::uniform_int_distribution<size_t> dist(0, tasks.size() - 1);
    for (auto& student : listStudents) {
        student.getEq(tasks[dist(gen)]);
    }
}

void Teacher::askToSolve() {
    for (auto& student : listStudents) {
        student.solveEq();
    }
}

void Teacher::getResults() {
    for (auto& student : listStudents) {
        uncheckedTasks.push_back(student.sendResult());
    }
}

void Teacher::checkResults() {
    double eps = 1e-7;
    for (auto& letter : uncheckedTasks) {
        bool res1 = false;
        bool res2 = false;
        if (std::isnan(letter.res1) && std::isnan(letter.eq.sol1)) {
            res1 = true;
        }
        else {
            if (fabs(letter.res1 - letter.eq.sol1) < eps) {
                res1 = true;
            }
        }
        if (std::isnan(letter.res2) && std::isnan(letter.eq.sol2)) {
            res2 = true;
        }
        else {
            if (fabs(letter.res2 - letter.eq.sol2) < eps) {
                res2 = true;
            }
        }
        if (res1 && res2) {
            log[letter.name] += 1;
        }
    }
    uncheckedTasks.clear();
}

void Teacher::sendLog() {
    for (const auto& [name, score] : log) {
        std::cout << name << ": " << score << std::endl;
    }
}

Teacher::~Teacher() = default;