#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "algoritmos.hpp"

using namespace std;
using namespace std::chrono;

//Implementacion del bubble sort
/* Complejidad de tiempo
    Mejor caso: O(n)
    Peor caso: O(n^2)
    Caso promedio: O(n^2)
*/
void bubbleSort(int arr[], int n) {
    //n - 1 porque el último elemento ya estará ordenado
    for (int i = 0; i < n - 1; ++i) {
        //n - i - 1 porque los últimos i elementos ya estarán ordenados
        for (int j = 0; j < n - i - 1; ++j) {

            //Si el elemento actual es mayor que el siguiente
            if (arr[j] > arr[j + 1]) {
                //Intercambiar los elementos
                int temp = arr[j];
                //Intercambio de valores
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Implementacion del selection sort
/* Complejidad de tiempo
    Mejor caso: O(n^2)
    Peor caso: O(n^2)
    Caso promedio: O(n^2)
*/
void selectionSort(int arr[], int n) {
    //n - 1 porque el último elemento ya estará ordenado
    for (int i = 0; i < n - 1; ++i) {
        //Encontrar el elemento más pequeño en el array
        int min_index = i;

        //Buscar el elemento más pequeño en el array
        //Desde i + 1 hasta n, porque los primeros i elementos ya estarán ordenados
        for (int j = i + 1; j < n; ++j) {

            //Si el elemento actual es menor que el elemento más pequeño
            if (arr[j] < arr[min_index]) {
                //Actualizar el índice del elemento más pequeño
                min_index = j;
            }
        }

        //Intercambiar el elemento más pequeño con el primer elemento no ordenado
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

//Implementacion del insertion sort
/* Complejidad de tiempo
    Mejor caso: O(n)
    Peor caso: O(n^2)
    Caso promedio: O(n^2)

*/
void insertionSort(int arr[], int n) {
    //Empezar desde el segundo elemento
    //xq el algoritmo compara el elemento actual con el anterior
    for (int i = 1; i < n; ++i) {

        //Guardar el elemento actual
        int key = arr[i];
        //Guardar el índice del elemento anterior
        int j = i - 1;

        //Mover los elementos del array que son mayores que el elemento actual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            //Decrementar el índice
            --j;
        }
        //sale cuando se llega al final del array o el elemento actual es mayor que el elemento anterior

        //Insertar el elemento actual en la posición correcta
        arr[j + 1] = key;
    }
}

//Implementacion partition

int partition(int arr[], int low, int high) {
    //Pivote es el último elemento
    int pivot = arr[high];

    //Índice del elemento más pequeño
    int i = low - 1;

    //Recorrer el array
    for (int j = low; j < high; ++j) {
        //Si el elemento actual es menor que el pivote
        if (arr[j] < pivot) {
            //Incrementar el índice del elemento más pequeño
            ++i;
            //Intercambiar los elementos
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //Intercambiar el pivote con el elemento en la posición correcta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    //Retornar el índice del pivote
    return i + 1;
}

//Implementacion quick sort
/* Complejidad de tiempo
    Mejor caso: O(n log n)
    Peor caso: O(n^2)
    Caso promedio: O(n log n)
*/
void quickSort(int arr[], int low, int high) {
    //Mientras el índice más bajo sea menor que el índice más alto
    if (low < high) {
        //Dividir el array en dos partes
        int pi = partition(arr, low, high);
        //Recursivamente ordenar las dos partes

        //Ordenar la parte izquierda
        quickSort(arr, low, pi - 1);

        //Ordenar la parte derecha
        quickSort(arr, pi + 1, high);
    }
}