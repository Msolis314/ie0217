#include <iostream>
using namespace std;

// perform bubble sort

void bubbleSort(int array[],int size){
    //loop to access each array element
    int total_swaps = 0;
    for (int step = 0;step <size;++step){

        //loop to compare array elements
        for (int i = 0;i <size - step - 1;++i){

            //compare two adjacent elements
            //change > to < to sort in descending order
            if (array[i] > array[i + 1]){

                //swap if elements are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }

        total_swaps++;
    }
    cout << "Total swaps in ordinary bubble sort: " << total_swaps << endl;
}

//Optimized bubble sort

void bubbleSortOptimized(int array[],int size){
    
    //loop to access each array element
    int total_swaps = 0;
    for (int step = 0; step < (size -1);++step){

        //Check if swapping occurs
        int swapped = 0;

        //loop to compare two elements
        for (int i = 0; i < (size-step-1); ++i){

            //compare two array elements
            //change > to < to sort in descending order

            if (array[i] > array[i +1]){

                //swapping occurs if elements
                //are not in the intended order

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        //no swapping means the array is already sorted
        //so no need to further comparison
        if (swapped == 0){
            break;
        }
        total_swaps++;
    }
    cout << "Total swaps in optimized buble sort: " << total_swaps << endl;
}

//print array 
void printArray(int array[],int size){
    for (int i = 0;i <size;++i){
        cout << " " << array[i];
    }
    cout << "\n";
}


int main(){
    int data[] = {-2,45,0,11,-9};

    //find the array's length
    int size = sizeof(data)/sizeof(data[0]);

    bubbleSort(data,size);

    cout << "Sorted Array in Ascending Order og buble sort:\n";
    printArray(data,size);

    int data2[] = {-2,45,0,11,-9};
    cout << "Optimized Bubble Sort:\n";
    bubbleSortOptimized(data2,size);
    printArray(data2,size);
    return 0;
}