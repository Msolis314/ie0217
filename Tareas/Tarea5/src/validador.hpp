#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP 
#include <string>

class ValidadorEmail {
    private: 
        std::string email;
    public:
        void validarCorreo(std::string email,bool &valido);
        int countCharMatch(std::string email, std::string pattern);
        bool valExtention(std::string email);
        bool valDomain(std::string email);
        std::string getDomain(std::string email);
        bool valName(std::string email);
};

#endif // VALIDADOR_HPP