#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "stats.hpp"

template <typename T>
Statistics<T>::Statistics(const std::vector<T>& data) : data(data){
    if (data.empty()){
        throw std::invalid_argument("La lista de datos debe contener elementos");
    }
}

template <typename T>
double Statistics<T>::mean() const {
    T sum = 0;
    //Se itera sobre el vector de datos
    // Se utiliza & para pasar por referencia y no copia
    // const T& value sirve para que se itere sobre el vector de datos
    for(const T& value : data){
        sum += value;
    }
    //Se convierte a double para que la división sea decimal
    //Es necesario para que se devuelva un valor decimal
    return static_cast<double>(sum) / data.size();
}

template <typename T>
double Statistics<T>::standardDeviation() const {
    /*La desviación estándar es la raíz 
    cuadrada de la diferencia entre cada valor 
    y la media al cuadrado,
    */
    double meanValue = mean();
    double sumSquares = 0;

    for (const T& value : data){
        //Se  utiliza el metodo mean ya definido
        sumSquares += (value - meanValue) * (value - meanValue);
    }

    return std::sqrt(sumSquares / data.size());
}