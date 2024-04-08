#ifndef PLANETA_HPP
#define PLANETA_HPP
#include <string>
#include <iostream>
#include "Continente.hpp"
#include "Tools.hpp"
#define MAX_CONTINENTS 10

/// @brief Clase que representa un planeta.
///
/// Esta clase se encuentra compuesta por un arreglo de continentes.
class Planeta{
    private:
        /// @brief Numero de continentes.
        int numContinentes;
        std::string nombre;
    public:
        /// @brief Constructor de la clase Planeta, inicializa el nombre del planeta.
        Planeta(std::string nombre);

        Continente* continentes[MAX_CONTINENTS];

        /// @brief Establecer el numero de continentes.
        /// @note Se establece el numero de continentes en el constructor.
        void setNumContinentes();

        /// @brief Acceder al numero de continentes.
        /// @return Numero de continentes.
        int getNumContinentes();

        /// @brief Acceder a  un puntero al arreglo de  continentes.
        /// @return Puntero al arreglo de objetos continentes.
        Continente *getContinentes();

        /// @brief Establecer los continentes.
        ///
        /// Se solicita al usuario el nombre de los continentes y se crean los objetos continente.
        void setContinentes();

        /// @brief Mostrar los continentes
        ///
        /// Se muestran los nombres de los continentes almacenados en el arreglo de continentes.
        void displayContinents();

        std::string* getArrayNames();

        /// @brief Determinar si el avion puede pasar por un continente.
        ///
        /// Se determina si el avion puede pasar por un continente si este tiene mas de un pais con aeropuerto.
        void avion();

        /// @brief Mostrar la informacion de los continentes.
        ///
        /// Se muestra la informacion de los continentes almacenados en el arreglo de continentes.
        void print();

        /// @brief Agregar un pais a un continente de la eleccion del usuario.
        ///
        /// Se solicita al usuario el nombre del continente y se agrega un pais a este.
        void agregarPais();

        /// @brief Eliminar un pais de un continente de la eleccion del usuario.
        ///
        /// Se solicita al usuario el nombre del continente y se elimina un pais de este.
        void eliminarPais();

        /// @brief Comparar dos paises por medio de la sobrecarga del operador ==.
        ///
        /// Se solicita al usuario el nombre de los paises y se comparan.
        void compararPaises();

        /// @brief Destructor de la clase Planeta.
        ///
        /// Se eliminan los objetos continente.
        ~Planeta();
};


#endif // PLANETA_HPP