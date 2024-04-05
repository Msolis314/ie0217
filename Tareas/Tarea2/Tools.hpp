#ifndef TOOLS_HPP
#define TOOLS_HPP



int randomInt(int min, int max);

enum typeCountry {
    DESARROLLO,
    PRIMER_MUNDO,
    MAX_COUNTRIES = 1000    
};

bool checkPrime(int n);

bool checkIdInList(int id, int id_list[]);
#endif // TOOLS_HPP