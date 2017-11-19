//
// Head file for cppHtmlConverter class
//

#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>

class CppHtmlConverter {
private:
    std::string pathToCpp;
    std::string pathToHtml;
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
    CppHtmlConverter();
    explicit CppHtmlConverter(std::string pathToCpp);
    virtual ~CppHtmlConverter();
    const std::string &getPathToCpp() const;
    const std::string &getPathToHtml() const;
    friend std::istream &operator>>(std::istream &is, CppHtmlConverter &cppHtmlConverter);
    friend std::ostream &operator<<(std::ostream &os, const CppHtmlConverter &cppHtmlConverter);
    bool convertFile();
};