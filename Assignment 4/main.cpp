#include <iostream>
#include "CppHtmlConverter.h"
#include "FilePathExample.h"
using namespace std;

int main() {
    CppHtmlConverter converter;
    cout << "Please enter the full path to the cpp file (i.e " << pathExample << ")\n";
    cin >> converter;
    if (converter.convertFile()) {
        cout << "File output to: " << converter.getPathToHtml() << endl;
    } else {
        cerr << "Error converting file\n";
    }
    return 0;
}