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

        return true;

    }
    
}
bool ValidadorEmail:: valDomain(std::string email){
    std::string domain = getDomain(email);
    try{
        if(domain == ""){
            throw "El correo no es valido, no tiene un dominio";
        } 

        if (countCharMatch(domain,"[^.]")> 30 || countCharMatch(domain,"[^.]") < 3){
            throw "El correo no es valido, el dominio tiene un tamaño invalido";
        }
        if(std::regex_search(domain,std::regex("^[.]")) || std::regex_search(domain,std::regex("[.]$"))){
            throw "El correo no es valido, el dominio empieza o termina con un punto";
        }
        if(std::regex_search(domain,std::regex("[.]{2}"))){
            throw "El correo no es valido, el dominio tiene puntos seguidos";
        }
        if(countCharMatch(domain,"[^a-zA-Z.]") > 0){
            throw "El correo no es valido, el dominio tiene caracteres invalidos";
        }

    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }

    catch (const std::regex_error& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    std::cout << "Dominio valido" << std::endl;
    return true;


}
std::string ValidadorEmail:: getDomain(std::string email){
    std::regex pattern("@(.*?)\\.[a-zA-Z]{2,6}\\.{0,1}[a-zA-Z]{0,2}$");

    std::smatch match;
    if (std::regex_search(email,match,pattern))
    {
        if (match.size() > 1){

            return match[1].str();

        }
    }
    return "";
}

bool ValidadorEmail:: valName(std::string email){
    std::regex pattern("^(.*?)@");
    std::smatch match;
    std::regex_search(email,match,pattern);
    std::string nombre = match[1].str();
    try {
        if (countCharMatch(nombre,"[^.-_]") > 15){
            throw "El correo no es valido,excede el limite de 15 caracteres para el nombre" ;
        }
        
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }

    std::regex pattern3("^(?!.*[.\\-_]{2})[^.\\-_][a-zA-Z0-9\\._\\-]*[^.\\-_]$");

    std::smatch match3;
    std::regex_search(nombre,match3,pattern3);
    try {
        if(match3.size() > 0){
            std::cout << "Nombre valido" << std::endl;
            return true;
        }
        if (countCharMatch(nombre,"[^a-zA-Z0-9._-]") > 0){
            throw "El correo no es valido, el nombre tiene caracteres invalidos";
        }
        if(std::regex_search(nombre,std::regex("^[.\\-_]")) || std::regex_search(nombre,std::regex("[.\\-_]$"))){
            throw "El correo no es valido, el nombre empieza o termina con un punto";
        }
        if(std::regex_search(nombre,std::regex("[.\\-_]{2}"))){
            throw "El correo no es valido, el nombre tiene caracteres especiales seguidos";
        }
        if(countCharMatch(nombre,"[^a-zA-Z0-9._-]") > 0){
            throw "El correo no es valido, el nombre tiene caracteres invalidos";
        }
        if(countCharMatch(nombre,"^[-._]") > 1 || countCharMatch(nombre,"[-._]$") > 1){
            throw "El correo no es valido, el nombre empieza o termina con un caracter especial";
        }
        if(countCharMatch(nombre,"[.-_]{2}") > 0){
            throw "El correo no es valido, el nombre tiene caracteres especiales seguidos";
        }
    }
    catch (const char* msg){
        std::cout << msg << std::endl;
        return false;
    }

    catch (const std::regex_error& e){
        std::cerr << "Error: " << e.what() << std::endl;

        return false;
    }
    std::cout << "Nombre valido" << std::endl;
    return true;

}