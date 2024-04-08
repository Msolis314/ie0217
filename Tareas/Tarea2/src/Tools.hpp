#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <string>

/// @brief Genera un numero aleatorio entre min y max
/// @param min minimo
/// @param max maximo
/// @return entero aleatorio
int randomInt(int min, int max);

/// @brief Estructura con los paises por defecto
///
/// @note Esta estructura contiene los paises por defecto para cada continente real.
struct defaultCountries {
    std::string asiaPrimerMundo[4] = {"China","Kores del Sur","Japon","Singapur"};
    std::string africaPrimerMundo[4] = {"Sudafrica","Egipto","Nigeria","Kenia"};
    std::string europePrimerMundo[4] = {"Alemania","Francia","Reino Unido","Italia"};
    std::string americaPrimerMundo[4] = {"Estados Unidos","Canada","Brasil","Argentina"};
    std::string oceaniaPrimerMundo[4] = {"Australia","Nueva Zelanda"};

    std::string asiaDesarrollo[4] = {"India","Indonesia","Pakistán","Bangladesh"};
    std::string africaDesarrollo[4] = {"Etiopía","Ginea","Somalia","Congo"};
    std::string europeDesarrollo[4] = {"Ucrania","Grecia","Serbia","Rumania"};
    std::string americaDesarrollo[4] = {"Costa Rica","Salvador","México","Colombia"};
    std::string oceaniaDesarrollo[2] = {"Fiyi","Samoa"};
    
};

/// @brief Enumeracion con los tipos de paises
///
/// @note Esta enumeracion contiene los tipos de paises que se pueden crear.
/// @note DESARROLLO: Pais en desarrollo
/// @note PRIMER_MUNDO: Pais de primer mundo
/// @note MAX_COUNTRIES: Numero maximo de paises que se pueden crear
enum typeCountry {
    DESARROLLO,
    PRIMER_MUNDO,
    MAX_COUNTRIES = 200   
};


enum Continent{
    AFRICA,
    AMERICA,
    ASIA,
    EUROPE,
    OCEANIA
};

/// @brief Funcion para comprobar si un numero es primo
/// @param n numero a comprobar
/// @return True si es primo, False si no es primo
bool checkPrime(int n);

/// @brief Funcion para comprobar si el id del pais ya existe en la lista de ids
/// @param id id a comprobar
/// @param id_list la lista con los ids existentes
/// @return True si el id ya existe, False si no existe
bool checkIdInList(int id, int id_list[]);

bool checkContinent(std::string continent);
#endif // TOOLS_HPP