/**
    C++ header file for "octal.cpp".
    @file octal.hpp
    @author Devansh Singh
    @brief Header file for initializing OctalCode class.
    @date 01/03/2022
*/

#include <string>
#include "fileio.hpp"
#ifndef OCTAL_HPP
#define OCTAL_HPP

/**
    Implementation of Octal code cryptography technique.
*/
class OctalCode{
private:
    std::string data, file_path;
    bool is_file;
public:
    OctalCode(std::string data, bool file_path=false);
    std::string encrypt();
    std::string decrypt();
};

#endif