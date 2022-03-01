/**
    C++ header file for "caesar.cpp".
    @file caesar.h
    @author Devansh Singh
    @brief Header file for initializing CaesarCipher class.
    @date 01/03/2022
*/

#include <string>
#ifndef CAESAR_H

/**
    Implementation of Caesar cipher cryptography technique.
*/
class CaesarCipher{
private:
    std::string data;
    unsigned int key;
public:
    CaesarCipher(std::string user_data, unsigned int crypt_key);
    std::string encrypt();
    std::string decrypt();
};

#endif