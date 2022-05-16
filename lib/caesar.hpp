/**
    C++ header file for "caesar.cpp".
    @file caesar.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing CaesarCipher class.
    @date 01/03/2022
*/

#include <iostream>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef CAESAR_HPP
#define CAESAR_HPP

/**
    Implementation of Caesar cipher cryptography technique.
*/
class CaesarCipher: public Cipher {
private:
    std::string data, file_path;
    unsigned int offset;
    bool is_file;
public:
    CaesarCipher();
    CaesarCipher(std::string data, unsigned int key, bool is_file=false);
    friend std::ostream& operator<<(std::ostream &output, CaesarCipher &obj);
    friend std::istream& operator>>(std::istream &input, CaesarCipher &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif