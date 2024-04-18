#ifndef PARTITION_HPP
#define PARTITION_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "algoritmos.hpp"
using namespace std;

//Declaración de funciones

//Genera un array de enteros aleatorios
//Recibe un array de enteros y su tamaño
void generatedRandomArray(int arr[], int n);

//Mide el tiempo que tarda un algoritmo de ordenamiento en ordenar un array
//Recibe un puntero a una función, un array de enteros, su tamaño y el nombre del algoritmo
void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName);

//Mide el tiempo que tarda quickSort en ordenar un array
//Recibe un puntero a una función, un array de enteros, el índice más bajo, el índice más alto y el nombre del algoritmo
//Se necesita una función aparte para quickSort porque recibe  parámetros diferentes que los otros algoritmos
void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int,int), int arr[], int low,int high, string algorithmName);

#endif // PARTITION_HPP