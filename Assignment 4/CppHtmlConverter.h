//
// Head file for cppHtmlConverter class
//

#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <stdio.h>

class CppHtmlConverter {
private:
    std::string pathToCpp;
    std::string pathToHtml;
    std::string htmlFileName;
    struct replacement {
        std::regex rgx;
        std::string sub;
    };
    replacement swapFileExt = {std::regex ("\\.cpp$"), ".html"};
    std::vector<replacement> escapeList {
            {std::regex("&"), "&amp;"},
            {std::regex("<"), "&lt;"},
            {std::regex(">"), "&gt;"}
    };
    std::ifstream inputFile;
    std::ofstream outputFile;

public:
    const static int GOOD_FILE_PATH = 0;
    const static int BAD_FILE_PATH = 1;
    const static int BAD_FILE_TYPE = 2;
    int setPathToCpp(const std::string &pathToCpp);
    int setPathToHtml(const std::string &pathToHtml);
    CppHtmlConverter();
    explicit CppHtmlConverter(std::string pathToCpp);
    virtual ~CppHtmlConverter();
    const std::string &getPathToCpp() const;
    const std::string &getPathToHtml() const;
    friend std::ostream &operator<<(std::ostream &os, const CppHtmlConverter &cppHtmlConverter);
    bool convertFile();
    const std::string &getHtmlFileName() const;
    int setHtmlFileName(const std::string &htmlFileName);
};