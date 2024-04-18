#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>


//Declaración de funciones

//Bubble sort
//Ordena un array de enteros de menor a mayor 
//Recibe un array de enteros y su tamaño
void bubbleSort(int arr[], int n);

//Selection sort
//Ordena un array de enteros de menor a mayor
//Recibe un array de enteros y su tamaño
void selectionSort(int arr[], int n);

//Insertion sort
//Ordena un array de enteros de menor a mayor
//Recibe un array de enteros y su tamaño
void insertionSort(int arr[], int n);

//Se encarga de dividir el array en dos partes
int partition(int arr[],int low, int high);


//quick sort
//Ordena un array de enteros de menor a mayor
//Recibe un array de enteros, el índice más bajo y el índice más alto
void quickSort(int arr[], int low, int high);  

#endif // ALGORITMOS_HPP