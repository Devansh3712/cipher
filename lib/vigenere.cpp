/**
    Vigenere cipher C++ implementation.
    @file vigenere.cpp
    @author Devansh Singh
    @brief Vigenere cipher is a polyalphabetic substitution cipher in which
    the plaintext is replaced using a key and their equivalent in the
    Vigenere cipher table.
    @date 05/03/2022
*/

#include <string>
#include "vigenere.hpp"

VigenereCipher::VigenereCipher(std::string user_data, std::string crypt_key){
    data = user_data;
    key = extend_key(crypt_key);
}

/**
    Encrypt the plaintext using the initialized key.
    @returns Encrypted ciphertext.
*/
std::string VigenereCipher::encrypt(){
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = (data[index] - 'A' + (key[index] - 'A')) % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = (data[index] - 'a' + (key[index] - 'a')) % 26 + 'a';
        }
    }
    return data;
}

/**
    Decrypt the ciphertext using the initialized key.
    @returns Decrypted plaintext.
*/
std::string VigenereCipher::decrypt(){
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = (data[index] - 'A' - (key[index] - 'A') + 26) % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = (data[index] - 'a' - (key[index] - 'a') + 26) % 26 + 'a';
        }
    }
    return data;
}