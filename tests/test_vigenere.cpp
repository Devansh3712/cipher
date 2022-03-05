#include <cassert>
#include <string>
#include "../lib/vigenere.hpp"

int main(){
    std::string str = "test data", key="sdf", result = "lhxl iswf";
    VigenereCipher obj(str, key);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}