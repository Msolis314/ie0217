#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

    //Ejemplo 1

    //allocate memoru of int size to an int pointer
    int* ptr = (int*)malloc(sizeof(int)); // Lo que recibe es el size en bits de memory 

    //assign the value 5 to allocated memory
    *ptr = 5;
    
    cout << *ptr << endl; //Output 5

    //deallocate the memory
    free(ptr);

    //Ejemplo 2
    int* ptr2;
    ptr2 = (int*)calloc(5, sizeof(int)); // Lo que recibe es el numero de elementos y el size en bits de memory
    if (!ptr2){
        cout << "Memory allocation failed" << endl;
        exit(1);
    }

    cout << "Initializing values ..." << endl;
    for (int i = 0; i < 5; i++){
        ptr2[i] = i*2 +1;
    }

    cout << "Initialized values: " << endl;
    for (int i =0; i< 5;i++){
        cout << *(ptr2 + i) << endl;
    }
    free(ptr2);

    //Ejemplo 3
    float *ptr3, *new_ptr;
    ptr3 = (float*)malloc(5*sizeof(float));
    if (!ptr3){
        cout << "Memory allocation failed" << endl;
        exit(1);
    }

    //Initializing memory block 
    for (int i = 0; i < 5; i++){
        ptr3[i] = i*1.5;
    }

    /*reallocating memory*/
    new_ptr = (float*)realloc(ptr3, 10*sizeof(float));
    if (!new_ptr){
        cout << "Memory reallocation failed" << endl;
        exit(1);
    }
    //Initializing new memory block
    for (int i = 5; i < 10; i++){
        new_ptr[i] = i*2.5;
    }

    cout <<"Printing Values: " << endl;
    for (int i = 0; i < 10; i++){
        cout << new_ptr[i] << endl;
    }
    free(new_ptr);
    //free(ptr3);
    return 0;
}