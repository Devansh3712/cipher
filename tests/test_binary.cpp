#include <cassert>
#include <string>
#include "../lib/binary.hpp"

int main(){
    std::string str = "test data", result;
    result = "01110100 01100101 01110011 01110100 00100000 01100100 01100001 01110100 01100001";
    BinaryCode obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}