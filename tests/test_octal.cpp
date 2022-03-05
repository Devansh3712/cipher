#include <cassert>
#include <string>
#include "../lib/octal.hpp"

int main(){
    std::string str = "test data", result = "164 145 163 164 40 144 141 164 141";
    OctalCode obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}