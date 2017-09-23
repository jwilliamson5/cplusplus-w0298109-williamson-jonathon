//Demo of Random Generation

#include <iostream>
#include <string.h>
#include <sstream>
#include <conio.h>
#include <ctime>
using namespace std;

int main() {

//    srand(time(0));
//    for(int i=0; i<100; i++) {
//
//        cout << i + 1 << " " << rand() << endl; //not scaled (no range specified)
//
//    }
//    getch();

//    bool bRejected = false;
//    string fullName;
//    cout << "Please enter your full name: ";
//    getline(cin, fullName);
//    for(int i = 0; i < fullName.length() && !bRejected; i++) {
//
//        if(isalpha(fullName[i])) {
//            continue;
//        } else if(isspace(fullName[i])) {
//            continue;
//        } else {
//            cout << "Not valid\n";
//            getch();
//            break;
//        }
//
//    }

    float num = 123.456;
    cout << num << " Without magic formula\n";
    getch();

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "$" << num << " with magic formula\n";
    getch(); //beware of rounding
    return 0;
}