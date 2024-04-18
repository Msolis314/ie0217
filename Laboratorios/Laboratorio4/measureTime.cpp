#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "algoritmos.hpp"
#include "measureTime.hpp"
using namespace std;
using namespace std::chrono;

void generatedRandomArray(int arr[],int n) {
    //Semilla es la base para generar números aleatorios
    /*En una computadora, los números aleatorios 
    no son realmente aleatorios, 
    sino que son generados por un algoritmo.
    */
    srand(time(0));

    for (int i = 0; i < n; ++i){
        arr[i] = rand() % 10000; // números aleatorios entre 0 y 9999
    }
}

void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName) { 
    //La funcion recibe a un puntero a una funcion
    //Esto es para que se pueda pasar cualquier algoritmo de ordenamiento
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // Es lo mismo que hacer bubbleSort(arr, n);
    //Una forma generica de llamar a la funcion
    sortingAlgorithm(arr, n);
    high_resolution_clock::time_point stop = high_resolution_clock::now(); 

    //Calculo del tiempo usando la libreria chrono
    //duration_cast es una funcion que convierte el tiempo a la unidad que se le pase
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    //auto duration = duration_cast<microseconds>(stop - start);
    //auto se usa para que el compilador detecte el tipo de la variable

    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;

}

void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int,int), int arr[], int low,int high, string algorithmName) { 
    //La funcion recibe a un puntero a una funcion
    //Esto es para que se pueda pasar cualquier algoritmo de ordenamiento
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // Generico para quickSort
    sortingAlgorithm(arr, low, high);
    high_resolution_clock::time_point stop = high_resolution_clock::now(); 

    //Calculo del tiempo usando la libreria chrono
    //duration_cast es una funcion que convierte el tiempo a la unidad que se le pase
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    //auto duration = duration_cast<microseconds>(stop - start);
    //auto se usa para que el compilador detecte el tipo de la variable

    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;

}