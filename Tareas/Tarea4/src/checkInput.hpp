#ifndef CHECKINPUT_HPP
#define CHECKINPUT_HPP
#include <iostream>
#include <string>

/// @brief Clase ValidadorDeEntrada
/// @tparam T Parametro generico
template <class T>
class ValidadorDeEntrada {
    public:
        /// @brief Este metodo valida si el usuario ingreso un numero que corresponde al tipo de dato que se espera
        /// @param input entrada del usuario
        /// @param value puntero que va a contener el valor convertido
        /// @return True si el valor ingresado es del tipo de dato esperado, False si no
        bool validarTipoDato(std::string input, T *value);

        /// @brief Este metodo valida si el tamaño de la matriz es mayor a 0
        /// @param tamano El tamaño de la matriz
        /// @return True si el tamaño de la matriz es mayor a 0, False si no
        bool validarDimensiones(int tamano);
};
#endif // CHECKINPUT_HPP