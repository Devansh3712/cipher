/**
    C++ header file for "vigenere.cpp".
    @file vigenere.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing VigenereCipher class.
    @date 01/03/2022
*/

#include <iostream>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef VIGENERE_HPP
#define VIGENERE_HPP

/**
    Implementation of Vigenere cipher cryptography technique.
*/
class VigenereCipher: public Cipher {
private:
    std::string data, key, file_path;
    bool is_file;
public:
    VigenereCipher();
    VigenereCipher(std::string data, std::string key, bool is_file=false);
    static std::string extend_key(int length, std::string key);
    friend std::ostream& operator<<(std::ostream &output, VigenereCipher &obj);
    friend std::istream& operator>>(std::istream &input, VigenereCipher &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif
