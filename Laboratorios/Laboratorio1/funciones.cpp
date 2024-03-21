#include "Funciones.hpp"

void agregarContacto(Contacto listaContactos[],int &numContactos){
    Contacto nuevoContacto;
    std::cout << "Ingrese el nombre del contacto: ";
    /*Estoy haciendo un acto de fe en el usuario :<*/
    std::cin >> nuevoContacto.nombre;
    std::cout << "Ingrese el numero de telefono: ";
    std::cin >> nuevoContacto.telefono;
    /*
    Agregar el contacto al final del arreglo
    Primero se agrego el contacto en el indice
    luego se aumenta la variable que pasamos por referencia
    */
    listaContactos[numContactos++] = nuevoContacto;
}

void mostrarContactos(const Contacto listaContactos[], int numContactos){
    std::cout << "Lista de contactos: \n";

    for (int i = 0; i < numContactos; ++i){
        //Iteramos por el arreglo de contactos
        //Imprimimos el nombre y el telefono
        std::cout << "Nombre: "<< listaContactos[i].nombre << ", Telefono: " << listaContactos[i].telefono << "\n";

    }
}

void buscarContacto(const Contacto listaContactos[], int numContactos){
    std:: string nombreBusqueda;
    std::cout << "Ingrese el nombre del contacto a buscar: ";
    std::cin >> nombreBusqueda;
    bool encontrado = false;

    //iteramos por la lista de contactos
    for (int i = 0; i < numContactos; ++i){
        //Si encontramos el contacto se sale del ciclo
        if(listaContactos[i].nombre == nombreBusqueda){
            std::cout << "Nombre: " << listaContactos[i].nombre << ", Telefono: " << listaContactos[i].telefono << "\n";
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        std::cout << "Contacto no encontrado.\n";
    }

}