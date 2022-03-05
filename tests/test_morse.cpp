#include <cassert>
#include <string>
#include "../lib/morse.hpp"

int main(){
    std::string str = "test data", result = "-|.|...|-| |-..|.-|-|.-";
    MorseCode obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}