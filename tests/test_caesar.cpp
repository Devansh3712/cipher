#include <cassert>
#include <string>
#include "../lib/caesar.hpp"

int main(){
    std::string str = "test data", result = "docd nkdk";
    CaesarCipher obj(str, 10);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}