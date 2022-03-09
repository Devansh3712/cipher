/**
    C++ header file for "morse.cpp".
    @file morse.hpp
    @author Devansh Singh
    @brief Header file for initializing MorseCode class.
    @date 03/03/2022
*/

#include <map>
#include <string>
#include "fileio.hpp"
#ifndef MORSE_HPP
#define MORSE_HPP

/**
    Implementation of Morse code cryptography technique.
*/
class MorseCode{
private:
    std::string data, file_path;
    bool is_file;
    std::map<char, std::string> dict = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."},
        {'d', "-.."}, {'e', "."}, {'f', "..-."},
        {'g', "--."}, {'h', "...."}, {'i', ".."},
        {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
        {'m', "--"}, {'n', "-."}, {'o', "---"},
        {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},
        {'s', "..."}, {'t', "-"}, {'u', "..-"},
        {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
        {'y', "-.--"}, {'z', "--.."}, {'0', "-----"},
        {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."},
        {'-', "-....-"}, {'.', ".-.-.-"}
    };
public:
    MorseCode(std::string data, bool is_file=false);
    std::string encrypt();
    std::string decrypt();
};

#endif