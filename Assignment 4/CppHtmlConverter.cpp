//
// Implementation for CppHtmlConverter class
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

const std::string &CppHtmlConverter::getPathToHtml() const {
    return pathToHtml;
}

bool CppHtmlConverter::convertFile() {
    if(pathToCpp.empty() || pathToHtml.empty()) {
        return false;
    }
    inputFile.open(pathToCpp);
    if(inputFile.fail() || !outputFile.is_open()) {
        return false;
    }
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

int CppHtmlConverter::setPathToCpp(const std::string &pathToCpp) {
    inputFile.open(pathToCpp);
    if(inputFile.fail()) {
        return BAD_FILE_PATH;
    } else if(!std::regex_match(pathToCpp, std::regex("^.*\\.cpp$"))) {
        inputFile.close();
        return BAD_FILE_TYPE;
    }
    inputFile.close();
    CppHtmlConverter::pathToCpp = pathToCpp;
    return GOOD_FILE_PATH;
}

int CppHtmlConverter::setPathToHtml(const std::string &pathToHtml) {
    std::string path = pathToHtml + "/thisIsATestFileThisShouldntBeHereDeleteThis.html";
    std::ofstream testFile;
    testFile.open(path);
    if(testFile.fail()) {
        return BAD_FILE_PATH;
    }
    testFile.close();
    CppHtmlConverter::pathToHtml = pathToHtml;
    std::remove(path.c_str());
    return GOOD_FILE_PATH;
}

const std::string &CppHtmlConverter::getHtmlFileName() const {
    return htmlFileName;
}

int CppHtmlConverter::setHtmlFileName(const std::string &htmlFileName) {
    if(pathToHtml.empty()) {
        return BAD_FILE_PATH;
    }
    outputFile.clear();
    outputFile.open(pathToHtml + "/" + htmlFileName + ".html");
    if(outputFile.fail()) {
        return BAD_FILE_TYPE;
    }
    pathToHtml.append("/" + htmlFileName + ".html");
    CppHtmlConverter::htmlFileName = htmlFileName;
}
