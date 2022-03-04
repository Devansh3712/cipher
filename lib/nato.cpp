/**
    NATO phonetic code C++ implementation.
    @file nato.cpp
    @author Devansh Singh
    @brief NATO phonetic code is an alphabet created for oral
    telecommunications, in order to spell words correctly.
    @date 04/03/2022
*/

#include <cctype>
#include <string>
#include <vector>
#include "nato.hpp"

/**
    Constructor for the NATOPhoneticCode class.
    @param user_data Data to encrypt/decrypt.
*/
NATOPhoneticCode::NATOPhoneticCode(std::string user_data){
    data = user_data;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string NATOPhoneticCode::encrypt(){
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            std::string current = dict[std::tolower(data[index])];
            current[0] = std::toupper(current[0]);
            result += current;
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
    return data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string NATOPhoneticCode::decrypt(){
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
    for(auto item: chars){
        result += item[0];
    }
    data = result;
    return data;
}