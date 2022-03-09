/**
    Morse code C++ implementation.
    @file morse.cpp
    @author Devansh Singh
    @brief Morse code is a cipher where letters of plaintext are represented as
    sequences of dots and dashes.
    @date 03/03/2022
*/

#include <cctype>
#include <string>
#include <vector>
#include "morse.hpp"

/**
    Constructor for the MorseCode class.
    @param data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
MorseCode::MorseCode(std::string data, bool is_file){
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
std::string MorseCode::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            result += dict[std::tolower(data[index])];
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            result += dict[data[index]];
        }else{
            bool found = false;
            for(auto item: dict){
                if(item.first == data[index]){
                    result += item.second;
                    found = true;
                    break;
                }
            }
            if(!found){
                result += data[index];
            }
        }
        if(index != data.length() - 1){
            result += std::string("|");
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
std::string MorseCode::decrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    std::vector<std::string> chars;
    std::string current = "", result = "";
    for(int index = 0; index < data.length(); index++){
        if(data[index] != '|'){
            current += data[index];
        }else{
            chars.push_back(current);
            current = "";
        }
    }
    if(current.length()){
        chars.push_back(current);
    }
    for(auto morse: chars){
        bool found = false;
        for(auto item: dict){
            if(item.second == morse){
                result += item.first;
                found = true;
                break;
            }
        }
        if(!found){
            result += morse;
        }
    }
    data = result;
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}