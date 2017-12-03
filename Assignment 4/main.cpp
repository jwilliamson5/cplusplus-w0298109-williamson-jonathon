#include <iostream>
#include "CppHtmlConverter.h"
#include "FilePathExample.h"
using namespace std;

int main() {
    CppHtmlConverter converter;
    cout << "Please enter the full path to the cpp file (i.e " << pathExample << ")\n";
    int status = 1;
    string input;
    while (status != 0) {
        getline(cin, input);
        status = converter.setPathToCpp(input);
        switch(status) {
            case 1: //converter.BAD_FILE_PATH
                cerr << "Please enter a valid file path\n";
                break;
            case 2: //converter.BAD_FILE_TYPE
                cerr << "File must end with .cpp\n";
                break;
            default:
                break;
        }
    }

    cout << "Enter the path where you would like to save the file\n";
    while(true) {
        getline(cin, input);
        if(converter.setPathToHtml(input) == converter.BAD_FILE_PATH) {
            cerr << "Please enter a valid file path\n";
            continue;
        }
        break;
    }

    string htmlFileName;
    cout << "Enter a name for the HTML file (without the file extension)\n";
    while(true) {
        getline(cin, htmlFileName);
        if(converter.setHtmlFileName(htmlFileName) == converter.BAD_FILE_TYPE) {
            cerr << "Please enter a valid file name\n";
            continue;
        }
        break;
    }

    if (converter.convertFile()) {
        cout << "File output to: " << converter.getPathToHtml() << endl;
    } else {
        cerr << "Error converting file\n";
    }
    return 0;
}