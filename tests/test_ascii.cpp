#include <cassert>
#include <string>
#include "../lib/ascii.hpp"

int main(){
    std::string str = "test data", result = "116 101 115 116 32 100 97 116 97";
    ASCIICode obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}