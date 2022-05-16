/**
    Caesar cipher C++ implementation.
    @file caesar.cpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Caesar cipher is a substitution cipher in which each letter in the
    plaintext is replaced by a letter at some fixed positions down the alphabet.
    @date 01/03/2022
*/

#include "caesar.hpp"

/**
    Default constructor for the CaesarCipher class.
*/
CaesarCipher::CaesarCipher() {
    is_file = false;
}

/**
    Parameterized constructor for the Caesar cipher class.
    @param data Data to encrypt/decrypt.
    @param key Number of positions to shift.
    @param is_file Read/Write from a file. Defaults to false.
*/
CaesarCipher::CaesarCipher(std::string data, unsigned int key, bool is_file) {
    if(is_file) {
        file_path = data;
        this->is_file = true;
    }else {
        this->data = data;
        this->is_file = false;
    }
    offset = key;
}

/**
    Overload extraction (<<) operator for displaying data.
    @param output Reference to output stream.
    @param obj Reference to CaesarCipher object.
    @returns Reference to output stream.
*/
std::ostream& operator<<(std::ostream &output, CaesarCipher &obj) {
    output << obj.data;
    return output;
}

/**
    Overload insertion (>>) operator for taking data from user.
    @param input Reference to input stream.
    @param obj Reference to CaesarCipher object.
    @returns Reference to input stream.
*/
std::istream& operator>>(std::istream &input, CaesarCipher &obj) {
    std::getline(input, obj.data);
    input >> obj.offset;
    return input;
}

/**
    Encrypt the plaintext using the initialized key.
    @returns Encrypted ciphertext.
*/
std::string CaesarCipher::encrypt() {
    if(is_file) {
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++) {
        if(data[index] >= 'A' && data[index] <= 'Z') {
            data[index] = (data[index] + offset - 'A') % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z') {
            data[index] = (data[index] + offset - 'a') % 26 + 'a';
        }
    }
    if(is_file) {
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}

/**
    Decrypt the ciphertext using the initialized key.
    @returns Decrypted plaintext.
*/
std::string CaesarCipher::decrypt() {
    if(is_file) {
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++) {
        if(data[index] >= 'A' && data[index] <= 'Z') {
            data[index] = (data[index] + (26 - offset) - 'A') % 26 + 'A';
        }else if(data[index] >= 'a' && data[index] <= 'z') {
            data[index] = (data[index] + (26 - offset) - 'a') % 26 + 'a';
        }
    }
    if(is_file) {
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}
