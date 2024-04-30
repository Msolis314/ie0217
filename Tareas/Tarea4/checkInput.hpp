#ifndef CHECKINPUT_HPP
#define CHECKINPUT_HPP
#include <iostream>
#include <string>

template <class T>
class ValidadorDeEntrada {
    public:
        bool validarTipoDato(std::string input);
        bool validarDimensiones(int tamano);
};
#endif // CHECKINPUT_HPP