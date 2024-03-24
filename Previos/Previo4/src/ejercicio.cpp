#include <iostream>
#include "ejercicio.hpp"

Student::Student(double m){
    this->marks = m;
}

void calculateAverage(Student s1, Student s2){
    double average = (s1.marks + s2.marks) / 2;
    std::cout << "Average Marks = " << average << std::endl;
}