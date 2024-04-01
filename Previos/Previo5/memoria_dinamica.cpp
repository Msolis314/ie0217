#include <iostream>
using namespace std;

//Ejemplo 4
class Student {
    private:
        int age;
    public:
        //contructor initializes age to 12
        Student(): age(12) {}

        void getAge(){
            cout << "Age is: " << age << endl;
        }
};
int main(){

    // pointerVariable = new dataType;

    //declare an int pointer
    int* pointVar;

    //dinamically allocate memory
    //for an int variable
    pointVar = new int;

    //assign value to the variable memory 
    *pointVar = 45;

    //print the value stored in the memory
    cout << *pointVar << endl; //Output 45

    //deallocate the memory
    delete pointVar;

    //Ejemplo 2
    //declare an int pointer
    int* pointInt;

    //declare a float pointer
    float* pointFloat;

    //dynamically allocate memory
    pointInt = new int;
    pointFloat = new float;

    //assiging value to the memory
    *pointInt = 45;
    *pointFloat = 45.45f;

    cout << *pointInt << endl; //Output 45
    cout << *pointFloat << endl; //Output 45.45

    //deallocate the memory
    delete pointInt;
    delete pointFloat;

    //Ejemplo 3

    int num;
    cout << "Enter total number of students: ";
    cin >> num;
    float* ptr;

    //memory allocation of num number of floats
    ptr  = new float[num];

    cout << "Enter GPA of students." << endl;
    for(int i = 0; i < num; i++){
        cout << "Student " << i+1 << ": ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying GPA of students." << endl;
    for(int i = 0; i < num; i++){
        cout << "Student " << i+1 << ": " << *(ptr + i) << endl;
    }

    //ptr memory is released
    delete[] ptr;

    //Ejemplo 4

    //dynamically declare Student object
    Student* ptr2 = new Student;

    //call getAge() function
    ptr2->getAge();

    //ptr2 memory is released
    delete ptr2;
    return 0;

}