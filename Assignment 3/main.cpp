#include <iostream>
#include <regex>
#include "Student.h"
using namespace std;

int main() {
    while(true) {
        cout << "<enter \"q\" at any time to quit>\n";
        Student s1;
        string name;
        string course;
        cout << "Enter the first student's name: \n";
        while(true) {
            getline(cin, name);
            if(regex_match(name, regex("\\s*")) || name.empty()) {
                cerr << "Please enter a name.\n";
                continue;
            }
            break;
        }
        if(name == "q") {
            break;
        }
        s1.setName(name);
        cout << "Enter all of the student's courses. Type \"f\" and press enter when finished.\n";
        bool endMain = false;
        while(true) {
            getline(cin, course);
            if(course == "q") {
                endMain = true;
                break;
            } else if(course == "f") {
                break;
            } else if(regex_match(course, regex("\\s*")) || course.empty()) {
                cerr << "Please enter a course name or \"f\" to finish.\n";
                continue;
            }
            s1.addCourse(course);
            cout << to_string(s1.getNumCourses()) << ": " << s1.getCourseList()[s1.getNumCourses() - 1] << endl;
        }
        if(endMain) {
            break;
        }
        cout << s1 << endl;
        Student s2(s1);
        cout << "Enter the name of the second student:\n";
        while(true) {
            getline(cin, name);
            if(regex_match(name, regex("\\s*")) || name.empty()) {
                cerr << "Please enter a name.\n";
                continue;
            }
            break;
        }
        if(name == "q") {
            break;
        }
        s2.setName(name);
        s1.resetCourses();
        cout << s1 << s2;
        Student s3;
        s3 = s2;
        cout << "<Student 3>\n" << s3 << endl;
    }
    return 0;
}