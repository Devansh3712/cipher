/**
    C++ header file for "hex.cpp".
    @file hex.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing HexCode class.
    @date 05/03/2022
*/

#include <iostream>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef HEX_HPP
#define HEX_HPP

/**
    Implementation of Hex code cryptography technique.
*/
class HexCode: public Cipher {
private:
    std::string data, file_path;
    bool is_file;
public:
    HexCode();
    HexCode(std::string data, bool is_file=false);
    friend std::ostream& operator<<(std::ostream &output, HexCode &obj);
    friend std::istream& operator>>(std::istream &input, HexCode &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif