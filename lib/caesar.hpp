/**
    C++ header file for "caesar.cpp".
    @file caesar.hpp
    @author Devansh Singh
    @brief Header file for initializing CaesarCipher class.
    @date 01/03/2022
*/

#include <string>
#include "fileio.hpp"
#ifndef CAESAR_HPP
#define CAESAR_HPP

/**
    Implementation of Caesar cipher cryptography technique.
*/
class CaesarCipher{
private:
    std::string data, file_path;
    unsigned int offset;
    bool is_file;
public:
    CaesarCipher(std::string data, unsigned int key, bool is_file=false);
    std::string encrypt();
    std::string decrypt();
};

#endif