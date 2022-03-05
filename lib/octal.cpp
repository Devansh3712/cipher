/**
    Octal code C++ implementation.
    @file octak.cpp
    @author Devansh Singh
    @brief Octal code is a cipher where the ascii code of characters of the
    plaintext are converted to their octal equivalent.
    @date 05/03/2022
*/

#include <sstream>
#include <string>
#include <vector>
#include "octal.hpp"

/**
    Constructor for the OctalCode class.
    @param user_data Data to encrypt/decrypt.
*/
OctalCode::OctalCode(std::string user_data){
    data = user_data;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string OctalCode::encrypt(){
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        std::ostringstream octal;
        octal << std::oct << (int)data[index];
        result += octal.str();
        if(index != data.length() - 1){
            result += std::string(" ");
        }
    }
    data = result;
    return data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string OctalCode::decrypt(){
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
        std::ostringstream decimal;
        int num;
        std::istringstream(item) >> std::oct >> num;
        decimal << std::dec << num;
        result += (char)std::stoi(decimal.str());
    }
    data = result;
    return data;
}