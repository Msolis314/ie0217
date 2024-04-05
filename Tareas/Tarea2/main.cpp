#include <iostream>
#include <string>
#include "TiposPaises.hpp"
#include "Tools.hpp"

int main(){
    PrimerMundo pais1("Estados Unidos");
    pais1.print();
    PrimerMundo pais2("Alemania");
    pais2.print();
    Desarrollo pais3("Brasil");
    pais3.print();
    return 0;
}