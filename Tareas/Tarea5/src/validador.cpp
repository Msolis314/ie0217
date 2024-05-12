#include <regex>
#include <iostream>
#include "validador.hpp"

void ValidadorEmail:: validarCorreo(std::string email,bool &valido){
    try {
        if (countCharMatch(email,"@") != 1){
            throw "El correo no es valido, no tiene un solo @";
        }
    } 
    catch (const char* msg){
        std::cerr << msg << std::endl;
        bool valido = false;
        return;
    }
    if (!valName(email) || !valDomain(email) || !valExtention(email)){
        bool valido = false;
        return;
    } else {
        bool valido = true;
        std::cout << "Correo valido" << std::endl;
        return;
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

bool ValidadorEmail:: valExtention(std::string email){
    std::regex pattern("([.]{1}[a-zA-Z]{2,6}\\.{0,1}[a-zA-Z]{0,2})$");
    std::smatch match;
    std::regex_search(email,match,pattern);
    if(match.str().length()){
        return true;;
    }
    
}
bool ValidadorEmail:: valDomain(std::string email){
    std::string domain = getDomain(email);
    try{
        if(domain == ""){
            throw "El correo no es valido, no tiene un dominio";
        } 
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }
    try {
        if(countCharMatch(domain,"[^.]") > 30 || countCharMatch(domain,"[^.]") < 3){
            throw "El correo no es valido, el dominio tiene un tamaño invalido";

        }
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }
    try {
        if(countCharMatch(domain,"^.") > 1 || countCharMatch(domain,".$") > 1){
            throw "El correo no es valido, el dominio empieza o termina con un punto";
        }
    
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }
    try {
        if(countCharMatch(domain,"[.]{2}") > 0){
            throw "El correo no es valido, el dominio tiene puntos seguidos";
        }
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;}
    try{
        if(countCharMatch(domain,"[^a-zA-Z.]") > 0){
            throw "El correo no es valido, el dominio tiene caracteres invalidos";
        }
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    
    }


}
std::string ValidadorEmail:: getDomain(std::string email){
    std::regex pattern("^(.*?)@.*([.]{1}[a-zA-Z]{2,6}\\.{0,1}[a-zA-Z]{0,2})$");
    std::smatch match;
    if (std::regex_search(email,match,pattern))
    {
        if (match.size() > 1){
            return match.str(2);
        }
    }
    return "";
}

bool ValidadorEmail:: valName(std::string email){
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
        return false;
    }
    std::regex pattern3("^(?!.*[.-_]{2})[^.-_][a-zA-Z0-9\\._-]*[^.-_]@$");
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
            return false;
        } else if (countCharMatch(nombre,"[^.-_]$") > 1){
            std::cerr << msg << std::endl;
            std::cerr << "Termina con (.,-,_)" << std::endl;
            return false;
        } else {
            std::cerr << msg << std::endl;
            std::cerr << "Caracteres especiales seguidos" << std::endl;
            return false;
        }
    }

}