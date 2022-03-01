/**
    C++ header file for "atbash.cpp".
    @file atbash.h
    @author Devansh Singh
    @brief Header file for initializing AtbashCipher class.
    @date 01/03/2022
*/

#include <map>
#include <string>
#ifndef ATBASH_H

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
public:
    AtbashCipher(std::string user_data);
    std::string encrypt();
    std::string decrypt();
};

#endif