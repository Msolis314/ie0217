#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "HashTable.hpp"

int main(){
    cout << "Agenda telefonica" << endl;
    
    

    HashTable *tabla = new HashTable(10);
    tabla->insertar("Pedro", 987654321);
    tabla->insertar("Maria", 123456789);
    tabla->print();
    return 0;
}