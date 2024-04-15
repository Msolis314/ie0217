//Quick sort in C++
//O(n log n) en el mejor de los casos
//O(n^2) en el peor de los casos
//O(n log n) en el caso promedio
//Complejidad de espacio: O(log n)

#include <iostream>
using namespace std;

//function to swap two elements
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to print an array
void printArray(int array[],int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

//function to rearrange elements in an array
int partition(int array[],int low,int high) {
    //select the rightmost element as pivot
    int pivot = array[high];

    //pointer for greater element
    int i = (low - 1);

    //Traverse through all elements
    //compare each element with pivot
    for (int j = low; j <high;j++){
        if (array[j] <= pivot){
            //if element smaller than pivot is found
            //swap it with the greater element pointed by i
            i++;

            //swap element at i with element at j
            swap(&array[i],&array[j]);
        }
    }
    //swap pivot with the greater element at i
    swap(&array[i + 1],&array[high]);

    //return the partition point
    return (i + 1);
}

void quickSort(int array[],int low,int high){

    if(low < high){
        //find pivot element such that
        //element smaller than pivot are on the left
        //element greater than pivot are on the right
        int pi = partition(array,low,high);

        //recursive call on the left of pivot
        quickSort(array,low,pi - 1);

        //recursive call on the right of pivot
        quickSort(array,pi + 1,high);
    }
}

//driver code

int main(){
    int data[] = {8,7,2,1,0,9,6};

    int n = sizeof(data)/sizeof(data[0]);

    cout << "Unsorted Array:\n";
    printArray(data,n);

    //perform quicksort on data
    quickSort(data,0,n-1);
    cout << "Sorted array in ascending order:\n";
    printArray(data,n);
    return 0;
}