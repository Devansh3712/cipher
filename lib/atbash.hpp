/**
    C++ header file for "atbash.cpp".
    @file atbash.hpp
    @author Devansh Singh
    @brief Header file for initializing AtbashCipher class.
    @date 01/03/2022
*/

#include <map>
#include <string>
#include "fileio.hpp"
#ifndef ATBASH_HPP
#define ATBASH_HPP

/**
    Implementation of Atbash cipher cryptography technique.
*/
class AtbashCipher{
private:
    std::string data;
    std::map<char, char> dict;
    void create_dict(){
        int left = 65, right = 90;
        while(true){
            if(left > 90 && right < 65){
                break;
            }
            dict[(char)left++] = (char)right--;
        }
    }
    friend class FileIO;
public:
    AtbashCipher(std::string user_data);
    std::string encrypt();
    std::string decrypt();
    bool encrypt_file(std::string file_path);
    bool decrypt_file(std::string file_path);
};

#endif