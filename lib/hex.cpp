/**
    Hex code C++ implementation.
    @file hex.cpp
    @author Devansh Singh
    @brief Hex code is a cipher where the ascii code of characters of the
    plaintext are converted to their hexadecimal equivalent.
    @date 05/03/2022
*/

#include <sstream>
#include <string>
#include <vector>
#include "hex.hpp"

/**
    Constructor for the HexCode class.
    @param data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
HexCode::HexCode(std::string data, bool is_file){
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
std::string HexCode::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        std::ostringstream hexadecimal;
        hexadecimal << std::hex << (int)data[index];
        result += hexadecimal.str();
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
std::string HexCode::decrypt(){
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
        std::ostringstream decimal;
        int num;
        std::istringstream(item) >> std::hex >> num;
        decimal << std::dec << num;
        result += (char)std::stoi(decimal.str());
    }
    data = result;
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}