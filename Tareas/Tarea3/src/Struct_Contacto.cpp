#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
using namespace std;

#define DIFFERENCE_UPPER_LOWER_CASE 32
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
    int asciiValuesNames[numContactos];
    for (int i = 0; i < numContactos; i++){
        if (contactos[i] -> nombre.empty() == true){
            continue;
        }
        string name = contactos[i] -> nombre;
        lowerCasetoUpper(name);
        asciiValuesNames[i] = int(name[0]);
    }

    //Selection sort para ordenar los contactos alfabeticamente
    for (int i = 0; i < numContactos - 1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < numContactos; j++){
            if (asciiValuesNames[j] > asciiValuesNames[maxIndex]){
                maxIndex = j;
            }
        }
        cout << contactos[maxIndex]->nombre << " " << contactos[maxIndex]->telefono << endl;
        swapValues(&asciiValuesNames[i], &asciiValuesNames[maxIndex]);
    }

}

void swapValues(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void lowerCasetoUpper(string str){
    for (int i = 0; i < str.length(); i++){
        //Si el caracter es una letra minuscula, convertirlo a mayuscula
        if (str[i] >= 'a' && str[i] <= 'z'){
            //Diferencia entre mayusculas y minusculas en ASCII
            str[i] = str[i] - DIFFERENCE_UPPER_LOWER_CASE; 
        }
    }
}
void deleteContact(string nombre){
    int index = checkContactosExits(nombre);
    if (index == -1){
        cout << "El contacto no existe" << endl;
        return;
    }
    delete contactos[index];
    contactos[index] = nullptr;
    numContactos--;
    //Reorganizar el arreglo de contactos
    for (int i = index; i < numContactos; i++){
        contactos[i] = contactos[i + 1];
    }
   
}
void freeMemory(){
    for (int i = 0; i < numContactos; i++){
        delete contactos[i];
    }
}

