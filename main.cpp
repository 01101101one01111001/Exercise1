// main.cpp
#include "classes.h"
#include <tuple>


int main() {
    std::unordered_map<std::string, int> teachersMap;
    std::unordered_map<std::string, int> studentsMap;
    std::vector<std::string> teacherOrder;
    std::vector<std::string> studentOrder;

    processInput(teachersMap, studentsMap, teacherOrder, studentOrder);
    printResults(teachersMap, studentsMap, teacherOrder, studentOrder);

    return 0;
}
