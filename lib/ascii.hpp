/**
    C++ header file for "ascii.cpp".
    @file ascii.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing ASCIICode class.
    @date 05/03/2022
*/

#include <iostream>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef ASCII_HPP
#define ASCII_HPP

/**
    Implementation of ASCII code cryptography technique.
*/
class ASCIICode: public Cipher {
public:
    ASCIICode();
    ASCIICode(std::string data, bool is_file=false);
    friend std::ostream& operator<<(std::ostream &output, ASCIICode &obj);
    friend std::istream& operator>>(std::istream &input, ASCIICode &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif
