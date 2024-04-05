#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Pais.hpp"
#include "Tools.hpp"

int id_list[MAX_COUNTRIES] = {0};
int randomInt (int min, int max){
    // Semilla para generar numeros aleatorios
    srand(time(0));
    return rand() % (max - min + 1) + min;
}

bool checkPrime(int n){
    // Caso base, un numero negativo o 0 no es primo
    if (n <= 1){
        return false;
    }
    // Iteramos desde 2 hasta n-1
    //Un numero primo solo es divisible por 1 y por si mismo
    for (int i = 2; i < n; i++){
        // Si n es divisible por i, entonces no es primo
        if (n % i == 0){
            return false;
        }
    }
    // Si no se encontro un divisor, entonces es primo
    return true;
}

bool checkIdInList(int id, int id_list[]){
    for (int i = 0; i < MAX_COUNTRIES; i++){
        if (id_list[i] == id){
            return true;
        }
    }
    return false;
}