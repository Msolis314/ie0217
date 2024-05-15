/*! @file Validador.cpp
 @brief Implementacion de la clase ValidadorEmail
MIT License

Copyright (c) 2024 Msolis314

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <regex>
#include <iostream>
#include "validador.hpp"

/// @details Para validar un correo electronico se debe cumplir con las siguientes condiciones:
/// - El correo debe tener un solo @
/// - El correo debe tener un nombre valido
/// - El correo debe tener un dominio valido
/// - El correo debe tener una extension valida
void ValidadorEmail:: validarCorreo(std::string email,bool &valido){
    //Se verifica que el correo tenga un solo @
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

    //Se verifican las condiciones del nombre, dominio y extension
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

/// @details Para validar la extension de un correo electronico se debe cumplir con las siguientes condiciones:
/// - La extension debe tener entre 2 y 6 caracteres
/// - La extension debe tener solo caracteres alfabeticos
/// - La extension debe tener un punto al inicio
/// - La extension puede o no tener un punto por medio
/// - Si tiene un punto por medio, debe tener entre 0 y 2 caracteres alfabeticos despues del punto
/// - La extension no puede tener un punto al final
bool ValidadorEmail:: valExtention(std::string email){
    std::regex pattern("([.]{1}[a-zA-Z]{2,6}\\.{0,1}[a-zA-Z]{0,2})$");
    std::smatch match;
    std::regex_search(email,match,pattern);
    if(match.str().length()){
        std::cout << "Extension: " << match.str() << std::endl;
        std::cout << "Extension valida" << std::endl;
        return true;
    }
    try {
        if (countCharMatch(email,"([.]{1}[a-zA-Z]{2,6}\\.{0,1}[a-zA-Z]{0,2})$") > 6 || countCharMatch(email,"([.]{1}[a-zA-Z]{2,6}\\.{0,1}[a-zA-Z]{0,2})$") < 2){
            throw "El correo no es valido, la extension tiene un tamaño invalido";
        }
        if (std::regex_search(email,std::regex("[.]$"))){
            throw "El correo no es valido, la extension termina con un punto";
        }
    } catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }
    catch (const std::regex_error& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    std::cout << "Extension valida" << std::endl;
    return true;
    
}

/// @details Para validar el dominio de un correo electronico se debe cumplir con las siguientes condiciones:
/// - El dominio debe tener entre 3 y 30 caracteres
/// - El dominio no puede empezar ni terminar con un punto
/// - El dominio no puede tener puntos seguidos
/// - El dominio solo puede tener caracteres alfabeticos
/// - Debe tener al menos un punto en el medio
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
    std::cout << "Dominio: " << domain << std::endl;
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


/// @details Para validar el nombre de un correo electronico se debe cumplir con las siguientes condiciones:
/// - El nombre debe tener entre 1 y 15 caracteres
/// - El nombre no puede tener caracteres especiales
/// - El nombre no puede empezar ni terminar con un punto
/// - El nombre no puede tener caracteres especiales seguidos
/// - El nombre no puede tener caracteres especiales al inicio o al final
/// - El nombre no puede tener caracteres especiales seguidos
bool ValidadorEmail:: valName(std::string email){
    //Patron para obtener el nombre
    //^(.*?)@ indica que se va a obtener todo lo que este antes del @
    std::regex pattern("^(.*?)@");
    std::smatch match;
    std::regex_search(email,match,pattern);
    //Se obtiene el nombre
    //Se obtiene el primer grupo de captura
    std::string nombre = match[1].str();
    
    try {
        //Se cuentan todos los caracteres que no sean el punto, guion o guion bajo
        if (countCharMatch(nombre,"[^.-_]") > 15){
            throw "El correo no es valido,excede el limite de 15 caracteres para el nombre" ;
        }
        
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return false;
    }

    //Patron para validar el nombre
    std::regex pattern3("^(?!.*[.\\-_]{2})[^.\\-_][a-zA-Z0-9\\._\\-]*[0-9a-zA-Z][^.\\-_]$");
    std::smatch match3;
    std::regex_search(nombre,match3,pattern3);
    std::cout << match3[0].str() << std::endl;

    try {
        if(std::regex_match(nombre,match3,pattern3)){
            std::cout << "Nombre valido" << std::endl;
            return true;
        }
        //Se verifica que el nombre no tenga caracteres no permitidos
        if (countCharMatch(nombre,"[^a-zA-Z0-9._-]") > 0){
            throw "El correo no es valido, el nombre tiene caracteres invalidos";
        }
        //Se verifica que el nombre no tenga caracteres especiales al inicio o al final
        if((std::regex_search(nombre,std::regex("^[.\\\\-_]")) || std::regex_search(nombre,std::regex("[.\\\\-_]$"))) && (!std::regex_match(nombre,std::regex("^[^0-9].*[^0-9]$")))) {
            throw "El correo no es valido, el nombre empieza o termina con un punto, guion o guion bajo";
        }
        //Se verifica que el nombre no tenga caracteres especiales seguidos
        if(std::regex_search(nombre,std::regex("[.\\\\-_]{2}"))){
            throw "El correo no es valido, el nombre tiene caracteres especiales seguidos";
        }
        else{
            std::cout << "Nombre valido" << std::endl;
            return true;
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
    std::cout<< "Nombre:" << match3[0].str() << std::endl;
    std::cout << "Nombre valido" << std::endl;
    return true;

}