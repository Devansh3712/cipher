/**
    Caesar cipher C++ implementation.
    @file caesar.cpp
    @author Devansh Singh
    @brief Caesar cipher is a substitution cipher in which each letter in the plaintext
    is replaced by a letter somefixed positions down the alphabet.
    @date 01/03/2022
*/

#include <string>
#include "caesar.h"

/**
    Constructor for the Caesar cipher class.
    @param user_data Data to encrypt
    @param crypt_key Number of positions to shift
*/
CaesarCipher::CaesarCipher(std::string user_data, unsigned int crypt_key){
    CaesarCipher::data = user_data;
    CaesarCipher::key = crypt_key;
}

/**
    Encrypt the plaintext using the initialized key.
    @returns Ciphertext
*/
std::string CaesarCipher::encrypt(){
    for(int index = 0; index < CaesarCipher::data.length(); index++){
        if(CaesarCipher::data[index] >= 'A' && CaesarCipher::data[index] <= 'Z'){
            CaesarCipher::data[index] = (CaesarCipher::data[index] + CaesarCipher::key - 'A') % 26 + 'A';
        }else if(CaesarCipher::data[index] >= 'a' && CaesarCipher::data[index] <= 'z'){
            CaesarCipher::data[index] = (CaesarCipher::data[index] + CaesarCipher::key - 'a') % 26 + 'a';
        }
    }
    return CaesarCipher::data;
}

/**
    Decrypt the ciphertext using the initialized key.
    @returns Plaintext
*/
std::string CaesarCipher::decrypt(){
    for(int index = 0; index < CaesarCipher::data.length(); index++){
        if(CaesarCipher::data[index] >= 'A' && CaesarCipher::data[index] <= 'Z'){
            CaesarCipher::data[index] = (CaesarCipher::data[index] + (26 - CaesarCipher::key) - 'A') % 26 + 'A';
        }else if(CaesarCipher::data[index] >= 'a' && CaesarCipher::data[index] <= 'z'){
            CaesarCipher::data[index] = (CaesarCipher::data[index] + (26 - CaesarCipher::key) - 'a') % 26 + 'a';
        }
    }
    return CaesarCipher::data;
}