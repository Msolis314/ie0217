#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10 
int size = 0;

// Creating a stack
struct stack{
    int items[MAX]; // Array to store elements
    int top; // Cual es el indice del ultimo elemento
};

typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
}

// Check if the stack is full
int isFull(st *s){
    if (s->top == MAX -1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty

int isEmpty(st *s){
    if (s-> top == -1)
        return 1;
    else
        return 0;
    
}

//Add elements into stack
void push(st *s,int newitem){
    // Check if the stack is full
    if (isFull(s)){
        cout << "STACK FULL" << endl;
    }
    else{
        //Se incrementa el indice top y se agrega el nuevo elemento
        s->top++;
        s->items[s->top] = newitem;
    }
    size++;
}

// Remove element from stack
void pop(st *s){
    if (isEmpty(s)){
        cout << "\n STACK EMPTY \n";
    } else {
        cout << "Item popped = " << s->items[s->top] << endl;
        s->top--;
    }
    size--;
    cout << endl;
}

// Print elements of stack

void printStack(st *s){
    printf("Stack: ");
    for (int i = 0; i < size; i++){
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// Driver code
int main(){
    int ch;
    //Almacenar la direccion de memoria de la estructura
    st *s = (st*)malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);
    cout << "\nAfter popping out\n";
    printStack(s);
    free(s);
    return 0;
}