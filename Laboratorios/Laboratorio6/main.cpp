#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "stats.hpp"


int main(){
    try {

        std::vector<int> intData = {1, 2, 3, 4, 5};

        //Cuando se intancia la clase se pasa el tipo
        //de dato que es T
        Statistics<int> statsInt(intData); // Se ejecuta el constructor

        std::cout << "Media de intData: " << statsInt.mean() << std::endl;
        std::cout << "Desviacion estandar de intData: " << statsInt.standardDeviation() << std::endl;

        /**********/

        std::vector<double> doubleData = {1.5, 2.5, 3.5, 4.5, 5.5};

        Statistics<double> statsDouble(doubleData);

        std::cout << "Media de doubleData: " << statsDouble.mean() << std::endl;
        std::cout << "Desviacion estandar de doubleData: " << statsDouble.standardDeviation() << std::endl;

        /**************************/
        //Esto debería lanzar una excepción
        std::vector<int> emptyData;
        Statistics<int> statsEmpty(emptyData);

    } catch (const std::invalid_argument& e){
        //Se captura la excepcion y se imprime el mensaje
        std::cerr <<"Excepcion encontrada: " << e.what() << std::endl;
    }

    //Se retorna 0 y no un mensaje de error
    //xq se captura la excepcion
    return 0;
}

// Se incluye el archivo cpp para que el compilador
// pueda generar el codigo de la clase
// ya que se trabaja con templates
#include "stats.cpp"