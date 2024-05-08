#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>
#include <string>
/// @brief Estructura que contiene los parametros que el usuario debe ingresar en el programa
struct menu{
    int rowsA , colsA, rowsB, colsB;
    std::string input;
    int operacion;
    int tipoDato;
    int complexType;
    int beginRandom;
    int whichMatrix;

} typedef menu;
enum whichMatrix
{
    A = 1,
    B,
    BOTH
};
enum Operation
{
    SUMA = 1,
    RESTA,
    MULTIPLICACION
};
enum DataType
{
    INT = 1,
    FLOAT,
    DOUBLE,
    COMPLEX
};
enum MenuOptions
{
    GENERATE_RANDOM_NUMBERS = 1,
    PRINT_MATRICES,
    DO_OPERATION,
    EXIT
};

/// @brief Funcion para generar un numero aleatorio
/// @tparam T 
/// @param type 
/// @return 
template <typename T>
T randomNum(int type);


#endif // TOOL_HPP
