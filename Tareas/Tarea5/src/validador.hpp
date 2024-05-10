#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP 
#include <string>

class ValidadorEmail {
    private: 
        std::string email;
    public:
        void validarCorreo(std::string email);
        int countCharMatch(std::string email, std::string pattern);
};

#endif // VALIDADOR_HPP