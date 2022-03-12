/**
    Vigenere cipher C++ implementation.
    @file vigenere.cpp
    @author Devansh Singh
    @brief Vigenere cipher is a polyalphabetic substitution cipher in which
    the plaintext is replaced using a key and their equivalent in the
    Vigenere cipher table.
    @date 05/03/2022
*/

#include "vigenere.hpp"

/**
    Default constructor for the VigenereCipher class.
*/
VigenereCipher::VigenereCipher(){
    is_file = false;
}

/**
    Parameterized constructor for the Vigenere cipher class.
    @param data Data to encrypt/decrypt.
    @param key Number of positions to shift.
    @param is_file Read/Write from a file. Defaults to false.
*/
VigenereCipher::VigenereCipher(std::string data, std::string key, bool is_file){
    if(is_file){
        file_path = data;
        this->is_file = true;
    }else{
        this->data = data;
        this->is_file = false;
    }
    this->key = key;
}

/**
    Overload extraction (<<) operator for displaying data.
    @param output Reference to output stream.
    @param obj Reference to VigenereCipher object.
    @returns Reference to output stream.
*/
std::ostream& operator<<(std::ostream &output, VigenereCipher &obj){
    output << obj.data;
    return output;
}

/**
    Overload insertion (>>) operator for taking data from user.
    @param input Reference to input stream.
    @param obj Reference to VigenereCipher object.
    @returns Reference to input stream.
*/
std::istream& operator>>(std::istream &input, VigenereCipher &obj){
    std::getline(input, obj.data);
    input >> obj.key;
    return input;
}

/**
   Extend key to length of the data to be encrypted/decrypted.
   @param length Length of data.
   @param key Key to extend.
   @returns Extended key.
*/
std::string VigenereCipher::extend_key(int length, std::string key){
    if(key.length() >= length){
        return key;
    }
    int required_length = length - key.length();
    int initial_key_length = key.length();
    while(required_length > initial_key_length){
        key += key;
        required_length -= initial_key_length;
    }
    key += key.substr(0, required_length);
    return key;
}

/**
    Encrypt the plaintext using the initialized key.
    @returns Encrypted ciphertext.
*/
std::string VigenereCipher::encrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    key = extend_key(data.length(), key);
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = (data[index] - 'A' + (key[index] - 'A')) % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = (data[index] - 'a' + (key[index] - 'a')) % 26 + 'a';
        }
    }
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}

/**
    Decrypt the ciphertext using the initialized key.
    @returns Decrypted plaintext.
*/
std::string VigenereCipher::decrypt(){
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    key = extend_key(data.length(), key);
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = (data[index] - 'A' - (key[index] - 'A') + 26) % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = (data[index] - 'a' - (key[index] - 'a') + 26) % 26 + 'a';
        }
    }
    if(is_file){
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}