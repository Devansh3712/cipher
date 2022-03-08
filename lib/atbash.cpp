/**
    Atbash cipher C++ implementation.
    @file atbash.cpp
    @author Devansh Singh
    @brief Atbash cipher is a substitution cipher where all the letters are
    reversed in order.
    @date 01/03/2022
*/

#include <cctype>
#include <string>
#include "atbash.hpp"
#include "fileio.hpp"

/**
    Constructor for the Atbash cipher class.
    @param user_data Data to encrypt/decrypt.
*/
AtbashCipher::AtbashCipher(std::string user_data = ""){
    data = user_data;
    create_dict();
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string AtbashCipher::encrypt(){
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = dict[data[index]];
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = std::tolower(dict[std::toupper(data[index])]);
        }
    }
    return data;
}

/**
    Encrypt the plaintext from a text file.
    @returns True if ciphertext is created else false.
*/
bool AtbashCipher::encrypt_file(std::string file_path){
    FileIO file(file_path);
    data = file.read();
    data = encrypt();
    return file.write(data);
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string AtbashCipher::decrypt(){
    for(int index = 0; index < data.length(); index++){
        if(data[index] >= 'A' && data[index] <= 'Z'){
            data[index] = dict[data[index]];
        }else if(data[index] >= 'a' && data[index] <= 'z'){
            data[index] = std::tolower(dict[std::toupper(data[index])]);
        }
    }
    return data;
}

/**
    Decrypt the ciphertext from a text file.
    @returns True if plaintext is created else false.
*/
bool AtbashCipher::decrypt_file(std::string file_path){
    FileIO file(file_path);
    data = file.read();
    data = decrypt();
    return file.write(data);
}