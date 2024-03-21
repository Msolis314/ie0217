#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Contacto.hpp"

/*En los arreglos siempre se envia la direccion del primer elemento*/
void agregarContacto(Contacto listaContactos[], int &numContactos); // Me interesa agregar el contacto al final
void mostrarContactos(const Contacto listaContactos[], int numContactos);
void buscarContacto(const Contacto listaContactos[], int numContactos);

#endif // FUNCIONES_HPP