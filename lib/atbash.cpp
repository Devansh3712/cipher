/**
    Atbash cipher C++ implementation.
    @file atbash.cpp
    @author Devansh Singh
    @brief Atbash cipher is a substitution cipher where all the letters are
    reversed in order.
    @date 01/03/2022
*/

#include <cctype>
#include <string>
#include "atbash.hpp"
#include "fileio.hpp"

/**
    Constructor for the Atbash cipher class.
    @param user_data Data to encrypt/decrypt.
*/
AtbashCipher::AtbashCipher(std::string data, bool is_file){
    if(is_file){
        file_path = data;
        this->is_file = true;
    }else{
        this->data = data;
        this->is_file = false;
    }
    create_dict();
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string AtbashCipher::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = dict[data[index]];
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = std::tolower(dict[std::toupper(data[index])]);
        }
    }
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string AtbashCipher::decrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = dict[data[index]];
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = std::tolower(dict[std::toupper(data[index])]);
        }
    }
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}