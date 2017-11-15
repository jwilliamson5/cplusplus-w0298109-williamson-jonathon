#include <iostream>
#include <fstream>
#include <regex>
#include "CppHtmlConverter.h"
using namespace std;

int main() {
    CppHtmlConverter converter;
    cout << "Please enter the full path to the cpp file (i.e C:\\Some Directory\\mMyFile.cpp)\n";
    cin >> converter;
    if(converter.convertFile()) {
        cout << "File output to: " << converter.getPathToHtml() << endl;
    } else {
        cerr << "Error converting file\n";
    }
    return 0;
}