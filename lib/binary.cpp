/**
    Binary code C++ implementation.
    @file binary.cpp
    @author Devansh Singh
    @brief Binary code is a cipher where the ascii code of characters of the
    plaintext is converted to it's binary equivalent.
    @date 01/03/2022
*/

#include <bitset>
#include <string>
#include <vector>
#include "binary.hpp"

/**
    Constructor for the BinaryCode class.
    @param user_data Data to encrypt/decrypt.
*/
BinaryCode::BinaryCode(std::string user_data){
    BinaryCode::data = user_data;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string BinaryCode::encrypt(){
    std::string result = "";
    for(int index = 0; index < BinaryCode::data.length(); index++){
        std::string binary = std::bitset<8>((int)BinaryCode::data[index]).to_string();
        if(index != BinaryCode::data.length() - 1){
            result += binary + std::string(" ");
        }else{
            result += binary;
        }
    }
    BinaryCode::data = result;
    return BinaryCode::data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string BinaryCode::decrypt(){
    std::vector<std::string> chars;
    std::string current = "", result = "";
    for(int index = 0; index < BinaryCode::data.length(); index++){
        if(BinaryCode::data[index] != ' '){
            current += BinaryCode::data[index];
        }else{
            chars.push_back(current);
            current = "";
        }
    }
    if(current.length()){
        chars.push_back(current);
    }
    for(auto binary: chars){
        unsigned long decimal = std::bitset<8>(binary).to_ulong();
        result += (char)decimal;
    }
    BinaryCode::data = result;
    return BinaryCode::data;
}