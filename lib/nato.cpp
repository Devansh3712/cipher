/**
    NATO phonetic code C++ implementation.
    @file nato.cpp
    @author Devansh Singh
            Chirag Tyagi
    @brief NATO phonetic code is an alphabet created for oral
    telecommunications, in order to spell words correctly.
    @date 04/03/2022
*/

#include <cctype>
#include <vector>
#include "nato.hpp"

/**
    Default constructor for the NATOPhoneticCode class.
*/
NATOPhoneticCode::NATOPhoneticCode() {
    is_file = false;
}

/**
    Constructor for the NATOPhoneticCode class.
    @param data Data to encrypt/decrypt.
    @param is_file Read/Write from a file. Defaults to false.
*/
NATOPhoneticCode::NATOPhoneticCode(std::string data, bool is_file) {
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
    @param obj Reference to NATOPhoneticCode object.
    @returns Reference to output stream.
*/
std::ostream& operator<<(std::ostream &output, NATOPhoneticCode &obj) {
    output << obj.data;
    return output;
}

/**
    Overload insertion (>>) operator for taking data from user.
    @param input Reference to input stream.
    @param obj Reference to NATOPhoneticCode object.
    @returns Reference to input stream.
*/
std::istream& operator>>(std::istream &input, NATOPhoneticCode &obj) {
    std::getline(input, obj.data);
    return input;
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string NATOPhoneticCode::encrypt() {
    if(is_file) {
        FileIO file(file_path);
        data = file.read();
    }
    std::string result = "";
    for(int index = 0; index < data.length(); index++) {
        if(data[index] >= 'A' && data[index] <= 'Z') {
            std::string current = dict[std::tolower(data[index])];
            current[0] = std::toupper(current[0]);
            result += current;
        }else if(data[index] >= 'a' && data[index] <= 'z') {
            result += dict[data[index]];
        }else {
            bool found = false;
            for(auto item: dict) {
                if(item.first == data[index]){
                    result += item.second;
                    found = true;
                    break;
                }
            }
            if(!found) {
                result += data[index];
            }
        }
        if(index != data.length() - 1) {
            result += std::string("|");
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
std::string NATOPhoneticCode::decrypt() {
    if(is_file) {
        FileIO file(file_path);
        data = file.read();
    }
    std::vector<std::string> chars;
    std::string current = "", result = "";
    for(int index = 0; index < data.length(); index++) {
        if(data[index] != '|') {
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
        result += item[0];
    }
    data = result;
    if(is_file) {
        FileIO file(file_path);
        return (file.write(data) == true ? "0" : "1");
    }
    return data;
}
