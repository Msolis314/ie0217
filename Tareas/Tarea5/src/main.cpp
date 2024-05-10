#include <iostream>
#include <string>
#include "validador.hpp"

int main(){
    std::string a = "aa._-@gmail.com";
    ValidadorEmail v;
    v.validarCorreo(a);
    return 0;
}