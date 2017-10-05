#include <iostream>
#include <stdio.h>
#include "DayOfYear.h"
using namespace std;

int main() {
    int userInput;
    DayOfYear today;
    DayOfYear birthday;

    cout << "Birthday program\n";
    cout << "Enter this month as a # 1-12:\n";
    cin >> userInput;
    today.setMonth(userInput);
    cout << "Enter birthday months as a # 1-12:\n";
    cin >> userInput;
    birthday.setMonth(userInput);

    cout << "Birthday program\n";
    cout << "Enter this day as a # 1-31:\n";
    cin >> userInput;
    today.setDay(userInput);
    cout << "Enter birthday months as a # 1-31:\n";
    cin >> userInput;
    birthday.setDay(userInput);

    if(today.getMonth() == birthday.getMonth() && today.getDay() == birthday.getDay()) {
        cout << "Happy birthday!\n";
    } else {
        cout << "Sorry, today is not your birthday.\n";
    }
    today.output();
    birthday.output();
    cin.ignore();

    return 0;
}