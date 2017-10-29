//Implementation for Student class
#include <istream>
#include <iostream>
#include "Student.h"

Student::Student():
        name(""), numCourses(0), courseList(new std::string[numCourses]) {}

Student::Student(const Student &other):
        name(other.name), numCourses(other.numCourses) {
    std::cout << "<Copy constructor>\n";
    courseList = new std::string[numCourses];
    for(int i = 0; i < numCourses; i++) {
        courseList[i] = move(other.courseList[i]);
    }
}

Student::~Student() {
    std::cout << "<Destructor>\n";
    if(courseList != nullptr) {
        courseList = nullptr;
    }
}

Student& Student::operator=(const Student& other) {
    std::cout << "<Assignment operator>\n";
    assignValues(other.name, other.numCourses, other.courseList);
    return *this;
}

void Student::assignValues(std::string name, int numCourses, std::string courseList[]) {
    this->name = std::move(name);
    this->numCourses = numCourses;
    this->courseList = new std::string[numCourses];
    for(int i = 0; i < numCourses; i++) {
        this->courseList[i] = courseList[i];
    }
}

void Student::addCourse(std::string course) {
    auto *tmp = new std::string[numCourses];
    for(int i = 0; i < numCourses; i++) {
        tmp[i] = move(courseList[i]);
    }
    numCourses += 1;
    courseList = new std::string[numCourses];
    for(int i = 0; i < numCourses - 1; i++) {
        courseList[i] = move(tmp[i]);
    }
    courseList[numCourses - 1] = move(course);
}

std::string Student::toString() {
    std::string rtnString = getName() + "\n";
    std::string indent = "  ";
    for(int i = 0; i < numCourses; i++){
        rtnString += indent + courseList[i] + "\n";
    }
    return rtnString;
}

void Student::resetCourses() {
    this->numCourses = 0;
    this->courseList = new std::string[numCourses];
}

const std::string &Student::getName() const {
    return name;
}

void Student::setName(const std::string &name) {
    Student::name = name;
}

int Student::getNumCourses() const {
    return numCourses;
}

void Student::setNumCourses(int numCourses) {
    Student::numCourses = numCourses;
}

std::string *Student::getCourseList() const {
    return courseList;
}

void Student::setCourseList(std::string *courseList) {
    Student::courseList = courseList;
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    std::string rtnString = student.getName() + "\n";
    rtnString += std::to_string(student.getNumCourses()) + " courses:\n";
    std::string indent = "  ";
    for(int i = 0; i < student.getNumCourses(); i++){
        rtnString += indent + student.getCourseList()[i] + "\n";
    }
    os << rtnString;
    return os;
}
