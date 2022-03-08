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
#include "fileio.hpp"

/**
    Constructor for the ASCIICode class.
    @param user_data Data to encrypt/decrypt.
*/
ASCIICode::ASCIICode(std::string user_data = ""){
    data = user_data;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string ASCIICode::encrypt(){
    std::string result = "";
    for(int index = 0; index < data.length(); index++){
        result += std::to_string((int)data[index]);
        if(index != data.length() - 1){
            result += std::string(" ");
        }
    }
    data = result;
    return data;
}

/**
    Encrypt the plaintext from a text file.
    @returns True if ciphertext is created else false.
*/
bool ASCIICode::encrypt_file(std::string file_path){
    FileIO file(file_path);
    data = file.read();
    data = encrypt();
    return file.write(data);
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string ASCIICode::decrypt(){
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
    return data;
}

/**
    Decrypt the ciphertext from a text file.
    @returns True if plaintext is created else false.
*/
bool ASCIICode::decrypt_file(std::string file_path){
    FileIO file(file_path);
    data = file.read();
    data = decrypt();
    return file.write(data);
}