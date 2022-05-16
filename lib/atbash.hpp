/**
    C++ header file for "atbash.cpp".
    @file atbash.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing AtbashCipher class.
    @date 01/03/2022
*/

#include <iostream>
#include <map>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef ATBASH_HPP
#define ATBASH_HPP

/**
    Implementation of Atbash cipher cryptography technique.
*/
class AtbashCipher: public Cipher {
private:
    std::map<char, char> dict;
    void create_dict() {
        int left = 65, right = 90;
        while(true){
            if(left > 90 && right < 65){
                break;
            }
            dict[(char)left++] = (char)right--;
        }
    }
public:
    AtbashCipher();
    AtbashCipher(std::string user_data, bool is_file=false);
    friend std::ostream& operator<<(std::ostream &output, AtbashCipher &obj);
    friend std::istream& operator>>(std::istream &input, AtbashCipher &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif
