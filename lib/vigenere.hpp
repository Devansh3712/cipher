/**
    C++ header file for "vigenere.cpp".
    @file vigenere.hpp
    @author Devansh Singh
    @brief Header file for initializing VigenereCipher class.
    @date 01/03/2022
*/

#include <iostream>
#include <string>
#include "fileio.hpp"
#ifndef VIGENERE_HPP
#define VIGENERE_HPP

/**
    Implementation of Vigenere cipher cryptography technique.
*/
class VigenereCipher{
private:
    std::string data, key, file_path;
    bool is_file;
    std::string extend_key(std::string key){
        if(key.length() >= data.length()){
            return key;
        }
        int required_length = data.length() - key.length();
        int initial_key_length = key.length();
        while(required_length > initial_key_length){
            key += key;
            required_length -= initial_key_length;
        }
        key += key.substr(0, required_length);
        return key;
    }
public:
    VigenereCipher();
    VigenereCipher(std::string data, std::string key, bool is_file=false);
    friend std::ostream& operator<<(std::ostream &output, VigenereCipher &obj);
    friend std::istream& operator>>(std::istream &input, VigenereCipher &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif