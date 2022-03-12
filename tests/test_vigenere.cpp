#include <cassert>
#include "../lib/vigenere.hpp"
#include "../lib/fileio.hpp"

int main(){
    std::string str = "test data", key = "sdf", result = "lhxl iswf";
    VigenereCipher obj1(str, key);
    assert(obj1.encrypt() == result);
    assert(obj1.decrypt() == str);
}