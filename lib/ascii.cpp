/**
    ASCII code C++ implementation.
    @file binary.cpp
    @author Devansh Singh
    @brief ASCII code is a cipher where the characters of the plaintext are
    converted to their ASCII equivalent.
    @date 01/03/2022
*/

#include <string>
#include <vector>
#include "ascii.hpp"

/**
    Constructor for the ASCIICode class.
    @param data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
ASCIICode::ASCIICode(std::string data, bool is_file){
    if(is_file){
        file_path = data;
        this->is_file = true;
    }else{
        this->data = data;
        this->is_file = false;
    }
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string ASCIICode::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        result += std::to_string((int)data[index]);
        if(index != data.length() - 1){
            result += std::string(" ");
        }
    }
    data = result;
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
std::string ASCIICode::decrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    std::vector<std::string> chars;
    std::string current = "", result = "";
    for(int index = 0; index < data.length(); index++){
        if(data[index] != ' '){
            current += data[index];
        }else{
            chars.push_back(current);
            current = "";
        }
    }
    if(current.length()){
        chars.push_back(current);
    }
    for(auto item: chars){
        result += (char)std::stoi(item);
    }
    data = result;
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}