#include <iostream>
using namespace std;

class Student {
    public:
        double marks;
        double marks1, marks2;
        Student (double m): marks(m) {}
    
};

//Se pueden enviar objetos como argumentos a funciones
void calculateAverage(Student s1, Student s2){
    double average = (s1.marks + s2.marks) / 2;
    cout << "Average Marks = " << average << endl;
}

Student createStudent(){
    Student student(0.0); 
    student.marks1 = 96.5;
    student.marks2 = 75.0;

    cout << "Marks 1 = " << student.marks1 << endl;
    cout << "Marks 2 = " << student.marks2 << endl;
    return student;
}

int main(){
    Student student1(88.0), student2(56.0), student3(0.0);
    student3 = createStudent();
    

    calculateAverage(student1, student2);
    return 0;
}

