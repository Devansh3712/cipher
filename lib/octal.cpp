/**
    Octal code C++ implementation.
    @file octal.cpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Octal code is a cipher where the ascii code of characters of the
    plaintext are converted to their octal equivalent.
    @date 05/03/2022
*/

#include <sstream>
#include <vector>
#include "octal.hpp"

/**
    Default constructor for the OctalCode class.
*/
OctalCode::OctalCode() {
    is_file = false;
}

/**
    Constructor for the OctalCode class.
    @param user_data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
OctalCode::OctalCode(std::string data, bool is_file) {
    if(is_file) {
        file_path = data;
        this->is_file = true;
    }else {
        this->data = data;
        this->is_file = false;
    }
}

/**
    Overload extraction (<<) operator for displaying data.
    @param output Reference to output stream.
    @param obj Reference to OctalCode object.
    @returns Reference to output stream.
*/
std::ostream& operator<<(std::ostream &output, OctalCode &obj) {
    output << obj.data;
    return output;
}

/**
    Overload insertion (>>) operator for taking data from user.
    @param input Reference to input stream.
    @param obj Reference to OctalCode object.
    @returns Reference to input stream.
*/
std::istream& operator>>(std::istream &input, OctalCode &obj) {
    std::getline(input, obj.data);
    return input;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string OctalCode::encrypt() {
    if(is_file) {
        FileIO file(file_path);
        data = file.read();
    }
    std::string result = "";
    for(int index = 0; index < data.length(); index++) {
        std::ostringstream octal;
        octal << std::oct << (int)data[index];
        result += octal.str();
        if(index != data.length() - 1) {
            result += std::string(" ");
        }
    }
    data = result;
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
std::string OctalCode::decrypt() {
    if(is_file) {
        FileIO file(file_path);
        data = file.read();
    }
    std::vector<std::string> chars;
    std::string current = "", result = "";
    for(int index = 0; index < data.length(); index++) {
        if(data[index] != ' ') {
            current += data[index];
        }else {
            chars.push_back(current);
            current = "";
        }
    }
    if(current.length()) {
        chars.push_back(current);
    }
    for(auto item: chars) {
        std::ostringstream decimal;
        int num;
        std::istringstream(item) >> std::oct >> num;
        decimal << std::dec << num;
        result += (char)std::stoi(decimal.str());
    }
    data = result;
    if(is_file) {
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}
