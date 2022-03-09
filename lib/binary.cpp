/**
    Binary code C++ implementation.
    @file binary.cpp
    @author Devansh Singh
    @brief Binary code is a cipher where the ascii code of characters of the
    plaintext are converted to their binary equivalent.
    @date 01/03/2022
*/

#include <bitset>
#include <vector>
#include "binary.hpp"
#include "fileio.hpp"

/**
    Default constructor for the BinaryCode class.
*/
BinaryCode::BinaryCode(){
    is_file = false;
}

/**
    Parameterized constructor for the BinaryCode class.
    @param data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
BinaryCode::BinaryCode(std::string data, bool is_file){
    if(is_file){
        file_path = data;
        this->is_file = true;
    }else{
        this->data = data;
        this->is_file = false;
    }
}

/**
    Overload extraction (<<) operator for displaying data.
    @param output Reference to output stream.
    @param obj Reference to BinaryCode object.
    @returns Reference to output stream.
*/
std::ostream& operator<<(std::ostream &output, BinaryCode &obj){
    output << obj.data;
    return output;
}

/**
    Overload insertion (>>) operator for taking data from user.
    @param input Reference to input stream.
    @param obj Reference to BinaryCode object.
    @returns Reference to input stream.
*/
std::istream& operator>>(std::istream &input, BinaryCode &obj){
    std::getline(input, obj.data);
    return input;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string BinaryCode::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        std::string binary = std::bitset<8>((int)data[index]).to_string();
        result += binary;
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
std::string BinaryCode::decrypt(){
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
    for(auto binary: chars){
        unsigned long decimal = std::bitset<8>(binary).to_ulong();
        result += (char)decimal;
    }
    data = result;
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}