//Selection sort in C++
// O(n^2) en todos los casos
#include <iostream>
using namespace std;

// function to swap the the position of two elements
void swap(int *a,int *b){
    int temp = *a;// Save the value of a
    *a = *b;// Store the value of b in a
    *b = temp;// Store the value of a in b

}

//function to print an array
void printArray(int array[], int size){
    for (int i = 0;i <size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

//function to perform selection sort

void selectionSort(int array[],int size){

    //se llega hasta el penúltimo elemento
    //porque el último elemento ya estará en su lugar
    for (int step = 0;step <size -1 ; step++){
        int min_idx=step;
        //Se inicializa el índice del mínimo en el paso actual
        //Se busca el mínimo en el resto del array
        for (int i = step +1; i <size;i++) {

            //to sort in descending order, change > to < in this line
            //select the minimum element in each loop
            if (array[i]< array[min_idx])
                min_idx = i;
            
        }
        //put the min at the correct position
        swap(&array[min_idx],&array[step]);
    }
}

//driver code
int main(){
    int data[] = {20,12,10,15,2};

    //tamaño del array de forma genérica
    int size = sizeof(data)/sizeof(data[0]);
    selectionSort(data,size);
    cout << "Sorted array in Ascending Order:\n";
    printArray(data,size);
    return 0;
}