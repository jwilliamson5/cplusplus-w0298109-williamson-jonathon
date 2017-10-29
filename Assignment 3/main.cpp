#include <iostream>
#include <regex>
#include "Student.h"
using namespace std;

int main() {
    Student s1 = Student();
    string name;
    string course;
    cout << "Enter the first student's name: \n";
    getline(cin, name);
    s1.setName(name);
    cout << "Enter all of the student's courses.  \"f\" and press enter when finished.\n";
    while(true) {
        getline(cin, course);
        if(course == "f") {
            break;
        } else if(regex_match(course, regex("\\s*")) || course.empty()) {
            cout << "Please enter a course name or \"f\" to finish.\n";
            continue;
        }
        s1.addCourse(course);
    }
    cout << s1 << endl;
    cout << "Enter the name of the second student:\n";
    getline(cin, name);
    Student s2 = Student(s1);
    s2.setName(name);
    s1.resetCourses();
    cout << s1;
    cout << s2;
    Student s3 = s2;
    cout << "<Student 3>\n" << s3;
    return 0;
}