//Header file for Student class
#pragma once

#include <string>
#include <ostream>

class Student {
private:
    std::string name;
    int numCourses;
    std::string *courseList;
public:
    Student();
    Student(const Student& other);
    ~Student() noexcept;
    Student& operator= (const Student& other);
    void assignValues(std::string name, int numCourses, std::string *courseList);
    void addCourse(std::string course);
    std::string toString();
    void resetCourses();
    const std::string &getName() const;
    void setName(const std::string &name);
    int getNumCourses() const;
    void setNumCourses(int numCourses);
    std::string *getCourseList() const;
    void setCourseList(std::string *courseList);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};
