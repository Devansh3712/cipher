/**
    C++ header file for "vigenere.cpp".
    @file vigenere.hpp
    @author Devansh Singh
    @brief Header file for initializing VigenereCipher class.
    @date 01/03/2022
*/

#include <string>
#ifndef VIGENERE_HPP
#define VIGENERE_HPP

/**
    Implementation of Vigenere cipher cryptography technique.
*/
class VigenereCipher{
private:
    std::string data;
    std::string key;
    std::string extend_key(std::string crypt_key){
        if(crypt_key.length() >= data.length()){
            return crypt_key;
        }
        int required_length = data.length() - crypt_key.length();
        int initial_key_length = crypt_key.length();
        while(required_length > initial_key_length){
            crypt_key += crypt_key;
            required_length -= initial_key_length;
        }
        crypt_key += crypt_key.substr(0, required_length);
        return crypt_key;
    }
public:
    VigenereCipher(std::string user_data, std::string crypt_key);
    std::string encrypt();
    std::string decrypt();
};

#endif