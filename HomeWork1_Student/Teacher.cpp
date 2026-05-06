#include "Teacher.h"

constexpr double eps = 1e-8;

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
    for (auto& letter : uncheckedTasks) {
        bool res1 = false;
        bool res2 = false;
        if (std::isnan(letter.getRes1()) && std::isnan(letter.getEq().getRoot1())) {
            res1 = true;
        }
        else {
            if (fabs(letter.getRes1() - letter.getEq().getRoot1()) < eps) {
                res1 = true;
            }
        }

        if(std::isnan(letter.getRes2()) && std::isnan(letter.getEq().getRoot2())) {
            res2 = true;
        }
        else {
            if (fabs(letter.getRes2() - letter.getEq().getRoot2()) < eps) {
                res2 = true;
            }
        }
        if (res1 && res2) {
            log[letter.getName()] += 1;
        }
    }
    uncheckedTasks.clear();
}

void Teacher::sendLog() {
    for (const auto& [name, score] : log) {
        std::cout << name << ": " << score << std::endl;
    }
}