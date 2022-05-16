/**
    C++ header file for "nato.cpp".
    @file nato.hpp
    @author Devansh Singh
            Chirag Tyagi
    @brief Header file for initializing NATOPhoneticCode class.
    @date 04/03/2022
*/

#include <iostream>
#include <map>
#include <string>
#include "base.hpp"
#include "fileio.hpp"
#ifndef NATO_HPP
#define NATO_HPP

/**
    Implementation of NATO phonetic code cryptography technique.
*/
class NATOPhoneticCode: public Cipher {
private:
    std::map<char, std::string> dict = {
        {'a', "alpha"}, {'b', "bravo"}, {'c', "charlie"},
        {'d', "delta"}, {'e', "echo"}, {'f', "foxtrot"},
        {'g', "golf"}, {'h', "hotel"}, {'i', "india"},
        {'j', "juliet"}, {'k', "kilo"}, {'l', "lima"},
        {'m', "mike"}, {'n', "november"}, {'o', "oscar"},
        {'p', "papa"}, {'q', "quebec"}, {'r', "romeo"},
        {'s', "sierra"}, {'t', "tango"}, {'u', "uniform"},
        {'v', "victor"}, {'w', "whiskey"}, {'x', "xray"},
        {'y', "yankee"}, {'z', "zulu"}, {'0', "zero"},
        {'1', "one"}, {'2', "two"}, {'3', "three"},
        {'4', "four"}, {'5', "five"}, {'6', "six"},
        {'7', "seven"}, {'8', "eight"}, {'9', "nine"},
        {'-', "dash"}, {'.', "stop"}
    };
public:
    NATOPhoneticCode();
    NATOPhoneticCode(std::string data, bool is_file=false);
    friend std::ostream& operator<<(std::ostream &output, NATOPhoneticCode &obj);
    friend std::istream& operator>>(std::istream &input, NATOPhoneticCode &obj);
    std::string encrypt();
    std::string decrypt();
};

#endif
