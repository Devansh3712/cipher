/**
    Atbash cipher C++ implementation.
    @file atbash.cpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Atbash cipher is a substitution cipher where all the letters are
    reversed in order.
    @date 01/03/2022
*/

#include <cctype>
#include "atbash.hpp"

/**
    Default constructor for the AtbashCipher class.
*/
AtbashCipher::AtbashCipher() {
    is_file = false;
    create_dict();
}

/**
    Parameterized constructor for the Atbash cipher class.
    @param data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
AtbashCipher::AtbashCipher(std::string data, bool is_file) {
    if(is_file) {
        file_path = data;
        this->is_file = true;
    }else {
        this->data = data;
        this->is_file = false;
    }
    create_dict();
}

/**
    Overload extraction (<<) operator for displaying data.
    @param output Reference to output stream.
    @param obj Reference to AtbashCipher object.
    @returns Reference to output stream.
*/
std::ostream& operator<<(std::ostream &output, AtbashCipher &obj) {
    output << obj.data;
    return output;
}

/**
    Overload insertion (>>) operator for taking data from user.
    @param input Reference to input stream.
    @param obj Reference to AtbashCipher object.
    @returns Reference to input stream.
*/
std::istream& operator>>(std::istream &input, AtbashCipher &obj) {
    std::getline(input, obj.data);
    return input;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string AtbashCipher::encrypt() {
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++) {
        if(data[index] >= 'A' && data[index] <= 'Z') {
            data[index] = dict[data[index]];
        }else if(data[index] >= 'a' && data[index] <= 'z') {
            data[index] = std::tolower(dict[std::toupper(data[index])]);
        }
    }
    if(is_file) {
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string AtbashCipher::decrypt() {
    if(is_file){
        FileIO file(file_path);
        data = file.read();
    }
    for(int index = 0; index < data.length(); index++) {
        if(data[index] >= 'A' && data[index] <= 'Z') {
            data[index] = dict[data[index]];
        }else if(data[index] >= 'a' && data[index] <= 'z') {
            data[index] = std::tolower(dict[std::toupper(data[index])]);
        }
    }
    if(is_file) {
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}
