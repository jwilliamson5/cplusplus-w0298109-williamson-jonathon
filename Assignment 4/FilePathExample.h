//
// Created by jwill on 2017-11-16.
//

#pragma once

#include <iostream>
#include <string>

#ifdef _WIN32
const std::string pathExample = "C:\\Some Directory\\mMyFile.cpp";
#elif __linux__
const std::string pathExample = "/Path/to/file.cpp";
#else
const std::string pathExample = "<Error: Unknown operating system>";
#endif