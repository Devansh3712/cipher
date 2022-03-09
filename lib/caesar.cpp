/**
    Caesar cipher C++ implementation.
    @file caesar.cpp
    @author Devansh Singh
    @brief Caesar cipher is a substitution cipher in which each letter in the
    plaintext is replaced by a letter at some fixed positions down the alphabet.
    @date 01/03/2022
*/

#include <string>
#include "caesar.hpp"

/**
    Constructor for the Caesar cipher class.
    @param data Data to encrypt/decrypt.
    @param key Number of positions to shift.
    @param is_file Read/Write from a file. Defaults to false.
*/
CaesarCipher::CaesarCipher(std::string data, unsigned int key, bool is_file){
    if(is_file){
        file_path = data;
        this->is_file = true;
    }else{
        this->data = data;
        this->is_file = false;
    }
    offset = key;
}

/**
    Encrypt the plaintext using the initialized key.
    @returns Encrypted ciphertext.
*/
std::string CaesarCipher::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = (data[index] + offset - 'A') % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = (data[index] + offset - 'a') % 26 + 'a';
        }
    }
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}

/**
    Decrypt the ciphertext using the initialized key.
    @returns Decrypted plaintext.
*/
std::string CaesarCipher::decrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = (data[index] + (26 - offset) - 'A') % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = (data[index] + (26 - offset) - 'a') % 26 + 'a';
        }
    }
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}