#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <string>


int randomInt(int min, int max);

enum typeCountry {
    DESARROLLO,
    PRIMER_MUNDO,
    MAX_COUNTRIES = 295   
};

enum Continent{
    AFRICA,
    AMERICA,
    ASIA,
    EUROPE,
    OCEANIA
};




bool checkPrime(int n);

bool checkIdInList(int id, int id_list[]);
#endif // TOOLS_HPP