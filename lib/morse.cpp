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
    MorseCode::data = user_data;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string MorseCode::encrypt(){
    std::string result = "";
    for(int index = 0; index < MorseCode::data.length(); index++){
        if(MorseCode::data[index] >= 'A' && MorseCode::data[index] <= 'Z'){
            if(index != MorseCode::data.length() - 1){
                result += MorseCode::dict[std::tolower(MorseCode::data[index])] + std::string("|");
            }else{
                result += MorseCode::dict[std::tolower(MorseCode::data[index])];
            }
        }else if(MorseCode::data[index] >= 'a' && MorseCode::data[index] <= 'z'){
            if(index != MorseCode::data.length() - 1){
                result += MorseCode::dict[MorseCode::data[index]] + std::string("|");
            }else{
                result += MorseCode::dict[MorseCode::data[index]];
            }
        }else{
            if(index != MorseCode::data.length() - 1){
                result += MorseCode::data[index] + std::string("|");
            }else{
                result += MorseCode::data[index];
            }
        }
    }
    MorseCode::data = result;
    return MorseCode::data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string MorseCode::decrypt(){
    std::vector<std::string> chars;
    std::string current = "", result = "";
    for(int index = 0; index < MorseCode::data.length(); index++){
        if(MorseCode::data[index] != '|'){
            current += MorseCode::data[index];
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
        for(auto item: MorseCode::dict){
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
    MorseCode::data = result;
    return MorseCode::data;
}