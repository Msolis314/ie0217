#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP 
#include <string>

/// @brief Clase que valida un correo electronico
/// @details La clase ValidadorEmail valida un correo electronico, verificando que tenga un solo @, que tenga un nombre, un dominio y una extension
class ValidadorEmail {
    private: 
        /// @brief Correo electronico
        std::string email;
    public:
        void validarCorreo(std::string email,bool &valido);

        /// @brief Metodo que cuenta cuantas veces se repite un patron en una cadena
        /// @param email string que se va a analizar
        /// @param pattern patron regex que se va a buscar
        /// @return numero de veces que se repite el patron en la cadena
        int countCharMatch(std::string email, std::string pattern);

        /// @brief Metodo que valida la extension de un correo electronico
        /// @param email correo electronico
        /// @return true si la extension es valida, false si no
        bool valExtention(std::string email);

        /// @brief metodo que valida el dominio de un correo electronico
        /// @param email correo electronico
        /// @return true si el dominio es valido, false si no
        bool valDomain(std::string email);

        /// @brief Metodo que obtiene el dominio de un correo electronico
        /// @param email correo electronico
        /// @return dominio del correo electronico
        std::string getDomain(std::string email);

        /// @brief Metodo que valida el nombre de un correo electronico
        /// @param email correo electronico
        /// @return true si el nombre es valido, false si no
        bool valName(std::string email);
};

#endif // VALIDADOR_HPP