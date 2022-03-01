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

/**
    Constructor for the Atbash cipher class.
    @param user_data Data to encrypt/decrypt.
*/
AtbashCipher::AtbashCipher(std::string user_data){
    AtbashCipher::data = user_data;
    AtbashCipher::create_dict();
}

/**
    Encrypt the plaintext.
    @returns Encrypted ciphertext.
*/
std::string AtbashCipher::encrypt(){
    for(int index = 0; index < AtbashCipher::data.length(); index++){
        if(AtbashCipher::data[index] >= 'A' && AtbashCipher::data[index] <= 'Z'){
            AtbashCipher::data[index] = AtbashCipher::dict[AtbashCipher::data[index]];
        }else if(AtbashCipher::data[index] >= 'a' && AtbashCipher::data[index] <= 'z'){
            AtbashCipher::data[index] = std::tolower(AtbashCipher::dict[std::toupper(AtbashCipher::data[index])]);
        }
    }
    return AtbashCipher::data;
}

/**
    Decrypt the ciphertext.
    @returns Decrypted plaintext.
*/
std::string AtbashCipher::decrypt(){
    for(int index = 0; index < AtbashCipher::data.length(); index++){
        if(AtbashCipher::data[index] >= 'A' && AtbashCipher::data[index] <= 'Z'){
            AtbashCipher::data[index] = AtbashCipher::dict[AtbashCipher::data[index]];
        }else if(AtbashCipher::data[index] >= 'a' && AtbashCipher::data[index] <= 'z'){
            AtbashCipher::data[index] = std::tolower(AtbashCipher::dict[std::toupper(AtbashCipher::data[index])]);
        }
    }
    return AtbashCipher::data;
}