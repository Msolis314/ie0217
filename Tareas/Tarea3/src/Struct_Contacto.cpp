#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
using namespace std;
Contacto *contactos[MAX_CONTACTOS] = {nullptr};
int numContactos = 0;
void agregarContacto(string nombre, int telefono){

    if (numContactos == MAX_CONTACTOS){
        cout << "Memoria llena" << endl;
        return;
    }

    Contacto *newContacto;
    //Asignar memoria al nuevo contacto
    newContacto = new Contacto();
    if (newContacto == nullptr){
        cout << "No hay memoria disponible" << endl;
        return;
    }
    newContacto->nombre = nombre;
    newContacto->telefono = telefono;
    cout << newContacto->nombre << endl;
    

    if (numContactos == 0){
        cout << "No hay contactos" << endl;
        cout << "Agregando contacto" << endl;
        contactos[numContactos] = newContacto;
        numContactos++;
        return;
    }

    if (checkContactosExits(nombre) != -1){
        cout << "El nombre del contacto ya existe en la memoria celular" << endl;
        cout << "Desea sobreescribir el contacto (s/n)" << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 'n'){
            delete newContacto;
            return;
        }
        contactos[checkContactosExits(nombre)]->telefono = telefono;
        return;
    }
   

    contactos[numContactos] = newContacto;
    numContactos++;
    
}

int checkContactosExits(string nombre){
    for (int i = 0; i < numContactos; i++){
        if (contactos[i] -> nombre == nombre){
            cout << "El contacto existe" << endl;
            return i;
        }
    }
    return -1;
}

void printContactosAlphabetically(){
    for (int i = 0; i < numContactos; i++){
        if (contactos[i] -> nombre.empty() == false){
            cout << "Nombre: " << contactos[i] -> nombre << endl;
            cout << "Telefono: " << contactos[i] -> telefono << endl;
        }
    }
}

void freeMemory(){
    for (int i = 0; i < numContactos; i++){
        delete contactos[i];
    }
}

