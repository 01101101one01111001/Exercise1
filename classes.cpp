// classes.cpp
#include "classes.h"
#include <iostream>
#include <sstream>
#include <tuple>


Person::Person(const std::string& first, const std::string& last)
    : firstName(first), lastName(last) {}

std::string Person::getFullName() const {
    return firstName + " " + lastName;
}

Student::Student(const std::string& first, const std::string& last)
    : Person(first, last) {}

Teacher::Teacher(const std::string& first, const std::string& last)
    : Person(first, last) {}

void processInput(
    std::unordered_map<std::string, int>& teachersMap,
    std::unordered_map<std::string, int>& studentsMap,
    std::vector<std::string>& teacherOrder,
    std::vector<std::string>& studentOrder
) {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == ".") break;

        std::istringstream iss(line);
        std::string first, last;

        // Teacher
        iss >> first >> last;
        Teacher teacher(first, last);
        std::string teacherName = teacher.getFullName();

        if (teachersMap.find(teacherName) == teachersMap.end()) {
            teachersMap[teacherName] = 0;
            teacherOrder.push_back(teacherName);
        }

        // Students
        while (iss >> first >> last) {
            Student student(first, last);
            std::string studentName = student.getFullName();

            if (studentsMap.find(studentName) == studentsMap.end()) {
                studentsMap[studentName] = 0;
                studentOrder.push_back(studentName);
            }

            teachersMap[teacherName]++;
            studentsMap[studentName]++;
        }
    }
}

void printResults(
    const std::unordered_map<std::string, int>& teachersMap,
    const std::unordered_map<std::string, int>& studentsMap,
    const std::vector<std::string>& teacherOrder,
    const std::vector<std::string>& studentOrder
) {
    std::cout << "Teachers:\n";
    for (const auto& name : teacherOrder) {
        std::cout << "- " << name << ": " << teachersMap.at(name) << "\n";
    }

    std::cout << "\nStudents:\n";
    for (const auto& name : studentOrder) {
        std::cout << "- " << name << ": " << studentsMap.at(name) << "\n";
    }
}

