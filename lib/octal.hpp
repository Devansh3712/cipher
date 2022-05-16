/**
    C++ header file for "octal.cpp".
    @file octal.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing OctalCode class.
    @date 01/03/2022
*/

#include <iostream>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef OCTAL_HPP
#define OCTAL_HPP

/**
    Implementation of Octal code cryptography technique.
*/
class OctalCode: public Cipher {
private:
    std::string data, file_path;
    bool is_file;
public:
    OctalCode();
    OctalCode(std::string data, bool file_path=false);
    friend std::ostream& operator<<(std::ostream &output, OctalCode &obj);
    friend std::istream& operator>>(std::istream &input, OctalCode &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif
