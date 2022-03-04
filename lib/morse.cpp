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
    @param user_data Data to encrypt/decrypt.
*/
MorseCode::MorseCode(std::string user_data){
    data = user_data;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string MorseCode::encrypt(){
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            result += dict[std::tolower(data[index])];
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            result += dict[data[index]];
        }else{
            result += data[index];
        }
        if(index != data.length() - 1){
            result += std::string("|");
        }
    }
    data = result;
    return data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string MorseCode::decrypt(){
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
    return data;
}