#include <iostream>
#include <limits>
#include <cstdlib>
#include "Model.h"

void Model::readFile(std::vector<std::string>& v, const std::string& fName) {
    std::fstream f(fName);
    if (!f.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(f, line)) {
        v.push_back(line);
    }
}

int Model::readInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input error. Enter an integer: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

void Model::showMenu() {
    std::cout << "\n========= MENU =========\n";
    std::cout << "1. Distribute tasks to students\n";
    std::cout << "2. Ask students to complete assignments\n";
    std::cout << "3. Ask students to send solutions\n";
    std::cout << "4. Check the submitted solutions (" << t.countUncheckedLetters() << ")\n";
    std::cout << "5. Print Progress Log\n";
    std::cout << "6. Execute 1-5 at a time\n";
    std::cout << "0. Exit the program\n";
    std::cout << "========================\n";
    std::cout << "Choose the action (1-6, 0): ";
}

Model::Model() {
    std::vector<std::string> names;
    std::vector<std::string> eqStr;

    std::map<const std::string, int> log;
    std::vector<Equation> tasks;
    std::vector<Student> listStudents;
    
    readFile(names, "StudentsList.txt");
    readFile(eqStr, "TasksList.txt");

    for (const auto& name : names) {
        log[name];
        listStudents.push_back(name);
    }

    for (const auto& str : eqStr) {
        tasks.push_back(Equation(str));
    }

    t = Teacher(log, tasks, listStudents);
}

void Model::startModel() {
    bool running = true;
    while (running) {
        showMenu();
        int choice = readInt();

        system("cls");

        switch (choice) {
        case 1:
            std::cout << "\n=== Distribution of tasks ===\n";
            t.giveTasks();
            std::cout << "Tasks have been distributed.\n";
            break;

        case 2:
            std::cout << "\n=== Problem solving ===\n";
            t.askToSolve();
            std::cout << "The tasks have been solved.\n";
            break;

        case 3:
            std::cout << "\n=== Receiving emails ===\n";
            t.getResults();
            std::cout << "Emails have been accepted.\n";
            break;

        case 4:
            std::cout << "\n=== Checking solutions ===\n";
            t.checkResults();
            std::cout << "Solutions are checked, points are counted.\n";
            break;

        case 5:
            std::cout << "\n=== Progress table ===\n";
            t.sendLog();
            break;

        case 6:
            std::cout << "=== Executing 1-5 at a time ===\n";
            t.giveTasks();
            t.askToSolve();
            t.getResults();
            t.checkResults();
            std::cout << "\n=== Progress table ===\n";
            t.sendLog();
            break;

        case 0:
            std::cout << "Exiting the program.\n";
            running = false;
            break;

        default:
            std::cout << "Incorrect choice. Try again.\n";
        }
    }
}