#include <cassert>
#include <string>
#include "../lib/hex.hpp"

int main(){
    std::string str = "test data", result = "74 65 73 74 20 64 61 74 61";
    HexCode obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}