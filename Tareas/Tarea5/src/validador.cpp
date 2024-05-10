#include <regex>
#include <iostream>
#include "validador.hpp"

void ValidadorEmail:: validarCorreo(std::string email){
    std::regex pattern("^(.*?)@");
    std::smatch match;
    std::regex_search(email,match,pattern);
    std::string nombre = match.str();
    try {
        if (countCharMatch(nombre,"[^.-_]") > 15){
            throw "El correo no es valido,excede el limite de 15 caracteres para el nombre" ;
        }
        
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        abort();
    }
    std::regex pattern3("^(?!.*[.-_]{2})[^.-_][a-zA-Z0-9\\._-]*[^.-_]$");
    std::smatch match3;
    std::regex_search(nombre,match3,pattern3);
    try {
        if(!match3.str().length()){
            throw "El correo no es valido, el nombre no cumple con el formato";
        }
    }
    catch (const char* msg){
        if (countCharMatch(nombre,"^[^.-_]") > 1){
            std::cerr << msg << std::endl;
            std::cerr << "Empieza con (.,-,_)" << std::endl;
        } else if (countCharMatch(nombre,"[^.-_]$") > 1){
            std::cerr << msg << std::endl;
            std::cerr << "Termina con (.,-,_)" << std::endl;
        } else {
            std::cerr << msg << std::endl;
            std::cerr << "Caracteres especiales seguidos" << std::endl;
        }
        abort();
    }

}

int ValidadorEmail:: countCharMatch(std::string cadena, std::string pattern_search){
    std::regex pattern(pattern_search);
    std::smatch match;
    std::sregex_iterator iter(cadena.begin(),cadena.end(),pattern);
    std::sregex_iterator end;
    int count = 0;
    while(iter != end){
        //String que hace match con el patron
        std::smatch match = *iter;
        //Esto se debe hacer porque se quiere contar cuantas veces se repite el patron
        std::string match_str = match.str();

        //Se incrementa el contador
        count += match_str.length();
        iter++;
    }
    return count;
}