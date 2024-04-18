#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "algoritmos.hpp"
#include "measureTime.hpp"

using namespace std;
using namespace std::chrono;

int main(){
    //Tamaño del array
    const int SIZE = 10000;
    int arr[SIZE];

    //Benchmark para ver cual es el algoritmo de ordenamiento más rápido
    generatedRandomArray(arr, SIZE);

    measuringSortingTime(bubbleSort, arr, SIZE, "Bubble Sort");

    generatedRandomArray(arr, SIZE);
    measuringSortingTime(selectionSort, arr, SIZE, "Selection Sort");

    generatedRandomArray(arr, SIZE);
    measuringSortingTime(insertionSort, arr, SIZE, "Insertion Sort");

    generatedRandomArray(arr, SIZE);
    measuringQuickSortTime(quickSort, arr, 0, SIZE-1, "Quick Sort");
    return 0;
}