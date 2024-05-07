#ifndef CHECKINPUT_HPP
#define CHECKINPUT_HPP
#include <iostream>
#include <string>

template <class T>
class ValidadorDeEntrada {
    public:
        bool validarTipoDato(std::string input, T *value);
        bool validarTipoDatoComplejo(std::string input, std::complex<T> *value);
        bool validarDimensiones(int tamano);
};
#endif // CHECKINPUT_HPP