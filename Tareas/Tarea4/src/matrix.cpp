/*! @file matrix.cpp
 @brief Implementacion de la clase Matrix
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

#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include "checkInput.hpp"
#include "operaciones.hpp"
#include "matrix.hpp"
#include "tools.hpp"
using namespace std;

/// @details En el constructor de la clase Matrix se valida si las dimensiones de la matriz son validas
/// Si las dimensiones son validas, se procede a llenar la matriz
template <class T>
Matrix<T>::Matrix(int rows, int cols, int tipoDato, int complexType,int beginRandom){
    this -> tipoDato = tipoDato;
    //Si el tipo de dato es complejo, se guarda el tipo de dato de la parte real e imaginaria
    if (tipoDato == COMPLEX){
        this -> complexType = complexType;
    }

    //Si el usuario selecciona llenar las matrices con numeros random, se llena la matriz con numeros random
    try {
        if (!setDimensiones(rows, cols)){
            throw invalid_argument("Las dimensiones de la matriz no son validas");
        }
        //Si el constructor es llamado por la operacion de suma o resta, se llena la matriz con numeros random inicialmente
        if (isOP == true || beginRandom == 1){
            fillMatrixRandom();
        }
        else if (tipoDato == COMPLEX){
            llenarMatrizCompleja();
        } else {
            llenarMatriz();
        }
    } 
    catch (invalid_argument &e){
        cout << e.what() << endl;
        abort();
    }
    
}

/// @details Constructor default de la clase Matrix
template <class T>
Matrix<T>:: Matrix()= default;

/// @details Sobrecarga del operador + para matrices
template <class T>
Matrix<T> Matrix<T>:: operator+(Matrix<T> &b){
    OperacionesBasicas<T> operaciones;
    //Se valida si se pueden sumar las matrices
    if( operaciones.validarSumaResta(*this, b)){
        //Se retorna la matriz resultante de la suma
        return operaciones.suma(*this, b, this->tipoDato, this->complexType, 0);
    } else {
        cout << "No se puede realizar la suma" << endl;
        return Matrix<T>();}
}

/// @details Sobrecarga del operador - para matrices
template <class T>
Matrix<T> Matrix<T>:: operator-(Matrix &b){
    OperacionesBasicas<T> operaciones;
   //Se valida si se pueden restar las matrices
    if( operaciones.validarSumaResta(*this, b)){
        //Se retorna la matriz resultante de la resta
        return operaciones.resta(*this, b, this->tipoDato, this->complexType, 0);
    
    } else {
        cout << "No se puede realizar la resta" << endl;
        return Matrix<T>();}
   
}

/// @details Sobrecarga del operador * para matrices
template <class T>
Matrix<T> Matrix<T>:: operator*(Matrix &b){
    OperacionesBasicas<T> operaciones;
    //Se valida si se pueden multiplicar las matrices
    if( operaciones.validarMultiplicacion(*this, b)){
        //Se retorna la matriz resultante de la multiplicacion
        return operaciones.multiplicacion(*this, b, this->tipoDato, this->complexType, 0);
    }
}

/// @details Metodo que setea las dimensiones de la matriz
template <class T>
bool Matrix<T>::setDimensiones(int rows, int cols){
    ValidadorDeEntrada<int> validador;
    //Se valida si las dimensiones de la matriz son validas
    if (validador.validarDimensiones(rows) && validador.validarDimensiones(cols)){
        //Se setean las dimensiones de la matriz
        this->rows = rows;
        this->cols = cols;
        return true;
    }
    return false;
}

/// @details Metodo que llena la matriz si el tipo de dato es int, float o double
template <class T>
void Matrix<T> :: llenarMatriz(){
    ValidadorDeEntrada<T> validador;
    //Primer loop que recorre las filas de la matriz
    for ( int i = 0; i < this->rows; i++){
        vector<T> row;
        //Segundo loop que recorre las columnas de la matriz
        for( int col = 0; col < this-> cols ; col++){
            //variable que almacena el valor ingresado por el usuario
            string member;
            //variable que almacena el valor convertido a tipo T
            T value;

            cout << "Ingrese el elemento en el indice [" << i << "][" << col << "]: ";
            cin >> member;
            //Se valida si el valor ingresado por el usuario puede ser convertido a tipo T
            while (!validador.validarTipoDato(member, &value)){
                cout << "Ingrese el elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            }
            //Se guarda el valor convertido en la fila

            row.push_back(value);
        }
        this->matrix.push_back(row);
    }

}
/// @details Metodo que llena la matriz si el tipo de dato es complejo
template <class T>
void Matrix<T>::llenarMatrizCompleja(){
    ValidadorDeEntrada<T> validador;
    //Primer loop que recorre las filas de la matriz
    for ( int i = 0; i < this->rows; i++){
        vector<complex<T>> row;
        //Segundo loop que recorre las columnas de la matriz
        for( int col = 0; col < this-> cols ; col++){
            string member;
            T value;
            //Se pide al usuario que ingrese la parte real e imaginaria del numero complejo
            cout << "Ingrese la parte real del elemento en el indice [" << i << "][" << col << "]: ";
            cin >> member;
            while (!validador.validarTipoDato(member, &value)){
                cout << "Ingrese la parte real del elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            }
            T real = value;
            cout << "Ingrese la parte imaginaria del elemento en el indice [" << i << "][" << col << "]: ";
            cin >> member;
            while (!validador.validarTipoDato(member, &value)){
                cout << "Ingrese la parte imaginaria del elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            }
            T imag = value;
            complex<T> complejo(real, imag);
            row.push_back(complejo);
        }
        this->matrixCompleja.push_back(row);
    }

}

/// @details Metodo que imprime la matriz
template <class T>
void Matrix<T>::printMatrix(){
    //Si el tipo de dato es complejo, se imprime la matriz compleja
    if (this->tipoDato == COMPLEX){
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                cout << this->matrixCompleja[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
}

/// @details Metodo que obtiene las dimensiones de la matriz
/// @param rows puntero a la variable que almacena el numero de filas
/// @param cols puntero a la variable que almacena el numero de columnas
/// @note Se utiliza en las clases OperacionesBasicas y MenuFuncs
template <class T>
void Matrix<T>::getDims(int *rows, int *cols){
    *rows = this->rows;
    *cols = this->cols;
}

/// @details Metodo que llena la matriz con numeros random
template<class T>
void Matrix<T>::fillMatrixRandom() {
    //Si es complejo, se llena la matriz compleja con numeros random
    if (this-> tipoDato == COMPLEX) {
        for (int i = 0; i < this->rows; i++){
            vector<complex<T>> row;
            for (int j = 0; j < this->cols; j++){
                //Se utiliza la funcion randomNum para obtener un numero random
                //Del tipo de dato de la parte real e imaginaria
                T real = randomNum<T>(this->complexType);
                T imag = randomNum<T>(this->complexType);
                complex<T> complejo(real, imag);
                row.push_back(complejo);
            }
            this->matrixCompleja.push_back(row);
            } 
        } else {
        for (int i = 0; i < this->rows; i++){
            vector<T> row;
            for (int j = 0; j < this->cols; j++){
                //Se utiliza la funcion randomNum para obtener un numero random
                T num = randomNum<T>(this->tipoDato);
                row.push_back(num);
            }
            this->matrix.push_back(row); }
    }
}

/// @note Destructor de la clase Matrix que libera la memoria de la matriz
template <class T>
Matrix<T>::~Matrix(){
    vector<vector<T>>().swap(this->matrix);
}