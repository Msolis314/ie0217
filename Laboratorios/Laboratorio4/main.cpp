#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;
//Implementacion del bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Implementacion del selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

//Implementacion del insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

//Implementacion partition

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

//Implementacion quick sort

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void generatedRandomArray(int arr[],int n) {
    //Semilla es la base para generar números aleatorios
    /*En una computadora, los números aleatorios 
    no son realmente aleatorios, 
    sino que son generados por un algoritmo.
    */
    srand(time(0));

    for (int i = 0; i < n; ++i){
        arr[i] = rand() % 1000; // números aleatorios entre 0 y 999
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

    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //auto duration = duration_cast<microseconds>(stop - start);
    //auto se usa para que el compilador detecte el tipo de la variable

    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;

}

int main(){
    const int SIZE = 10000;
    int arr[SIZE];

    generatedRandomArray(arr, SIZE);

    measuringSortingTime(bubbleSort, arr, SIZE, "Bubble Sort");
    measuringSortingTime(selectionSort, arr, SIZE, "Selection Sort");
    measuringSortingTime(insertionSort, arr, SIZE, "Insertion Sort");
    return 0;
}