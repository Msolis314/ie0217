//Insertion sort in C++
//O(n^2) en el peor de los casos
//O(n) en el mejor de los casos
//O(n^2) en el caso promedio
//Complejidad de espacio: O(1)

#include <iostream>
using namespace std;

//Function to print an array
void printArray(int array[],int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int array[],int size){
    for (int step = 1; step < size; step++){
        int key = array[step];
        int j = step - 1;//Comparar key con cada elemento a la izquierda de él hasta que se encuentre un elemento más pequeño

        //Compare key with each element on the left of it until an element smaller 
        //than it is found
        //For descending order, change key < array[j] to key > array[j]
        while (key < array[j] && j >= 0){
            //Si key es más pequeño que el elemento en array[j], se mueve el elemento a la derecha
            array[j + 1] = array[j];
            --j;
        }
        //Se posiciona key en su lugar
        //Esto es porque key es mayor que el elemento en array[j] para salir del bucle
        array[j + 1] = key;
    }

}

//driver code
int main(){
    int data[] = {9,5,1,4,3};

    int size = sizeof(data)/sizeof(data[0]);
    insertionSort(data,size);
    cout << "Sorted array in ascending order:\n";
    printArray(data,size);
    return 0;
}