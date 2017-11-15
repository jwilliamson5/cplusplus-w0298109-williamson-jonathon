//
// Created by jwill on 2017-11-15.
//

#include "CppHtmlConverter.h"

CppHtmlConverter::CppHtmlConverter()
        :pathToCpp(""), pathToHtml("") {}

CppHtmlConverter::CppHtmlConverter(std::string pathToCpp)
        :pathToCpp(std::move(pathToCpp)) {
    pathToHtml = std::regex_replace(getPathToCpp(), swapFileExt.rgx, swapFileExt.sub);
}

CppHtmlConverter::~CppHtmlConverter() {
    if(inputFile.is_open()) inputFile.close();
    if(outputFile.is_open()) outputFile.close();
}

const std::string &CppHtmlConverter::getPathToCpp() const {
    return pathToCpp;
}

void CppHtmlConverter::setPathToCpp(const std::string &pathToCpp) {
    CppHtmlConverter::pathToCpp = pathToCpp;
}

const std::string &CppHtmlConverter::getPathToHtml() const {
    return pathToHtml;
}

void CppHtmlConverter::setPathToHtml(const std::string &pathToHtml) {
    CppHtmlConverter::pathToHtml = pathToHtml;
}

std::istream &operator>>(std::istream &is, CppHtmlConverter &cppHtmlConverter) {
    std::string input;
    while(is) {
        if(is.fail()) {
            is.clear();
        }
        std::getline(is, input);
        cppHtmlConverter.inputFile.open(input);
        if(cppHtmlConverter.inputFile.fail()) {
            std::cerr << "Please enter a valid file path.\n";
            cppHtmlConverter.inputFile.open(cppHtmlConverter.pathToCpp);
            is.fail();
            continue;
        }
        if(!regex_match(input, std::regex("^.*\\.cpp$"))) {
            std::cerr << "File path must end with .cpp\n";
            cppHtmlConverter.inputFile.close();
            is.fail();
            continue;
        }
        cppHtmlConverter.inputFile.close();
        cppHtmlConverter.pathToHtml = std::regex_replace(input, cppHtmlConverter.swapFileExt.rgx, cppHtmlConverter.swapFileExt.sub);
        cppHtmlConverter.pathToCpp = std::move(input);
        break;
    }
}

std::ostream &operator<<(std::ostream &os, const CppHtmlConverter &cppHtmlConverter) {
    std::ifstream htmlFile;
    htmlFile.open(cppHtmlConverter.pathToHtml);
    if(htmlFile.fail()) {
        os << "&lt;Error: HTML file not found&gt;\n";
    } else {
        std::string line;
        while(getline(htmlFile, line)) {
            os << line << std::endl;
        }
        htmlFile.close();
    }
    return os;
}

bool CppHtmlConverter::convertFile() {
    if(pathToCpp.empty()) {
        return false;
    }
    inputFile.open(pathToCpp);
    if(inputFile.fail()) {
        return false;
    }
    outputFile.open(pathToHtml);
    outputFile << "<PRE>\n";
    std::string line;
    while(getline(inputFile, line)) {
        for(auto const& r: escapeList) {
            line = std::regex_replace(line, r.rgx, r.sub);
        }
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile << "</PRE>\n";
    outputFile.close();
    return true;
}