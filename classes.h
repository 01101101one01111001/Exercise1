// classes.h
#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>


class Person {
protected:
    std::string firstName;
    std::string lastName;
public:
    Person(const std::string& first, const std::string& last);
    std::string getFullName() const;
};

class Student : public Person {
public:
    Student(const std::string& first, const std::string& last);
};

class Teacher : public Person {
public:
    Teacher(const std::string& first, const std::string& last);
};

void processInput(
    std::unordered_map<std::string, int>& teachersMap,
    std::unordered_map<std::string, int>& studentsMap,
    std::vector<std::string>& teacherOrder,
    std::vector<std::string>& studentOrder
);

void printResults(
    const std::unordered_map<std::string, int>& teachersMap,
    const std::unordered_map<std::string, int>& studentsMap,
    const std::vector<std::string>& teacherOrder,
    const std::vector<std::string>& studentOrder
);

#endif

