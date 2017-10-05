// Header file for DayOfYear class


#pragma once //cause the current source file to be included once

#include <iostream>

class DayOfYear {
private:
    int month;
    int day;
public:
    DayOfYear();
    ~DayOfYear();
    void setMonth(int month);
    int getMonth();
    void setDay(int day);
    int getDay();
    void output();




};
