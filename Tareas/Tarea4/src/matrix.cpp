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
#include "menuFuncs.hpp"
using namespace std;

/// @details Constructor de la clase Matrix con parametros, lanzara una excepcion si las dimensiones de la matriz no son validas
template <class T>
Matrix<T>::Matrix(int rows, int cols, menu &menu){
    this->tipoDato = menu.tipoDato;
    if (this->tipoDato == COMPLEX){
        this->complexType = menu.complexType;
    }
    try {
        if (!setDimensiones(rows, cols)){
            throw invalid_argument("Las dimensiones de la matriz no son validas");
        }
        if (menu.beginRandom == 1){
            fillMatrixRandom();
        } else {
            if (this->tipoDato == COMPLEX){
                llenarMatrixComplejo();
            }
            else {
            llenarMatriz();
            }
        }
        
    } 
    catch (invalid_argument &e){
        cout << e.what() << endl;
        abort();
    }
    
}
template <class T>
Matrix<T>:: Matrix()= default;

template <class T>
Matrix<T> Matrix<T>:: operator+(Matrix<T> &b){
    OperacionesBasicas<T> operaciones;
    
    if( operaciones.validarSumaResta(*this, b)){
        return operaciones.suma(*this, b);
    }
}

template <class T>
Matrix<T> Matrix<T>:: operator-(Matrix &b){
    OperacionesBasicas<T> operaciones;
   
    if( operaciones.validarResta(*this, b)){
        return operaciones.resta(*this, b);
    
    }
   
}

template <class T>
Matrix<T> Matrix<T>:: operator*(Matrix &b){
    OperacionesBasicas<T> operaciones;
    
    Matrix<T> result(this->rows, cols);
    if( operaciones.validarMultiplicacion(*this, b)){
        return operaciones.multiplicacion(*this, b);
    }
}
template <class T>
bool Matrix<T>::setDimensiones(int rows, int cols){
    ValidadorDeEntrada<int> validador;
    if (validador.validarDimensiones(rows) && validador.validarDimensiones(cols)){
        this->rows = rows;
        this->cols = cols;
        return true;
    }
    return false;
}

template <class T>
void Matrix<T> :: llenarMatriz(){
    ValidadorDeEntrada<T> validador;
    
    for ( int i = 0; i < this->rows; i++){
        vector<T> row;
        for( int col = 0; col < this-> cols ; col++){
            string member;
            T value;
            cout << "Ingrese el elemento en el indice [" << i << "][" << col << "]: ";
            cin >> member;
            while (!validador.validarTipoDato(member, &value)){
                cout << "Ingrese el elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            }
            /*
            try {
                if (!validador.validarTipoDato(member)){
                    throw invalid_argument("El tipo de dato ingresado no es valido");
                }
            }
            catch (invalid_argument &e){
                cout << e.what() << endl;
                cout << "Ingrese el elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            } */

            row.push_back(value);
        }
        this->matrix.push_back(row);
    }

}

template <class T>
void Matrix<T>::llenarMatrixComplejo(){
    //Esta funcion llena la matriz con numeros complejos
    ValidadorDeEntrada<T> validador;
    for ( int i = 0; i < this->rows; i++){
        vector<T> row;
        for( int col = 0; col < this-> cols ; col++){
            //Se debe ingresar la parte real e imaginaria de un numero complejo
            string member;
            T value;

            //Se pide la parte real del numero complejo
            cout << "Ingrese la parte real del elemento en el indice [" << i << "][" << col << "]: ";
            cin >> member;

            //Se verifica si el valor ingresado es un numero de tipo T
            while (!validador.validarTipoDato(member, &value)){
                cout<< "Valor invalido, intente de nuevo.\n";
                cout << "Ingrese la parte real del elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            }
            T real = value;
            cout << "Ingrese la parte imaginaria del elemento en el indice [" << i << "][" << col << "]: ";
            cin >> member;

            //Se verifica si el valor ingresado es un numero de tipo T
            while (!validador.validarTipoDato(member, &value)){
                cout<< "Valor invalido, intente de nuevo.\n"
                cout << "Ingrese la parte imaginaria del elemento en el indice [" << i << "][" << col << "]: ";
                cin >> member;
            }
            T imag = value;
            complex<T> complejo(real, imag);
            row.push_back(complejo);
        }
        this->matrix.push_back(row);
    }

}

template <class T>
void Matrix<T>::printMatrix(){
    for (int i = 0; i < this->rows; i++){
        for (int j = 0; j < this->cols; j++){
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
void Matrix<T>::getDims(int *rows, int *cols){
    *rows = this->rows;
    *cols = this->cols;
}


template <class T>
void Matrix<T>::fillMatrixRandom(){
    if (this-> tipoDato == COMPLEX){
        for (int i = 0; i < this->rows; i++){
            vector<T> row;
            for (int j = 0; j < this->cols; j++){
                T real = randomNum<T>(this->complexType);
                T imag = randomNum<T>(this->complexType);
                complex<T> complejo(real, imag);
                row.push_back(complejo);
            }
            this->matrix.push_back(row);
        }
    } else {
        for (int i = 0; i < this->rows; i++){
            vector<T> row;
            for (int j = 0; j < this->cols; j++){
                T value = randomNum<T>(this->tipoDato);
                row.push_back(value);
            }
            this->matrix.push_back(row);
        }
    }
}
template <class T>
Matrix<T>::~Matrix(){
    cout << "Destructor" << endl;
    vector<vector<T>>().swap(this->matrix);
}
#include "checkInput.cpp"
#include "operaciones.cpp"