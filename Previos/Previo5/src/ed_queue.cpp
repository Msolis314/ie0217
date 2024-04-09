//Queue implementation in C++

#include <iostream>
#define SIZE 5
using namespace std;

class Queue{
    private:
        int items[SIZE],front,rear;
    public:
        Queue(){
            front = -1; //indice del primer elemento
            rear = -1;//indice del ultimo elemento
        }
    
    //Revisar si la cola esta llena
    bool isFull(){
        //El inicio de la cola es 0 y el final es SIZE - 1
        if (front == 0 && rear == SIZE -1){
            return true;
        }
        return false;
    }

    //Revisar si la cola esta vacia
    bool isEmpty(){
        if (front == -1)
            return true;//Si el frente es -1, la cola esta vacia
        else
            return false;
    }

    //Agregar elementos a la cola
    void enQueue(int element){
        if (isFull()){
            cout << "Queue is full";
        } else {
            if(front == -1) front = 0;//Si el frente es -1, la cola esta vacia, y por lo tanto se inicializa en 0
            rear++;
            items[rear] = element; //Se incrementa el indice rear y se agrega el nuevo elemento
            cout << endl
                 << "Inserted " << element << endl;
        }
    }

    //Eliminar elementos de la cola
    int deQueue(){
        int element;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return (-1);//Si la cola esta vacia, se regresa -1
        } else {
            element = items[front];
            if (front >= rear){
                front = -1;
                rear = -1;
            } /*Q has only one element, so we reset the queue after deleting it.*/
            else {
                front++;
            }
            cout << endl
                 << "Deleted -> " << element << endl;
            return (element);

        }

    }

    void display(){
        /*Function to display elements of Queue*/
        int i;
        if (isEmpty()){
            cout << endl
                 << "Empty Queue" << endl;
        } else {
            cout << endl
                << "Front index-> " << front << endl;
            
            cout << "Items -> ";
            for (i = front; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl
                 << "Rear index-> " << rear << endl;

        }
    }

};

int main(){
    Queue q;

    //deQueue is not possible on empty queue
    q.deQueue();

    //enQueue 5 elements
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    //6th element can't be added to the queue
    q.enQueue(6);

    q.display();

    //deQueue removes element entered first i.e. 1
    q.deQueue();

    //Now we have just 4 elements
    q.display();

    return 0;
}