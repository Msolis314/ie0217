#include <iostream>
using namespace std;
#define MI_PRIMER_DEFINE 925
#define BOOK_ID_MAX 10
enum seasons { 
    spring = 34,
    summer = 4, 
    autumn = 9, 
    winter = 32
};
enum week { 
    sunday, 
    monday, 
    tuesday, 
    wednesday, 
    thursday, 
    friday, 
    saturday
};
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
};
enum enumcito{
    carro = 34,
    casa = 4,
    arbol = 9,
    patio = 32
};
enum{
    CASA_BADILLA,
    CASA_ALVARADO,
    CASA_SOLANO,
    CASA_MAX
} casas_t;
int main(){

    //Ejemplo #1
    seasons s;
    s = summer;
    cout << "Summer = " << s << endl;

    //Ejemplo #2
    week today;
    today = wednesday;
    cout << "Day: " << today +1 << endl;

    //Ejemplo #3
    suit card;
    card = club;
    cout << "Size of enum: " << sizeof(card) << endl;
    

    //Ejemplo #4
    cout << "arbol = " << arbol << endl;

    /*El valor de BOOK_ID_MAX es PRE-procesado.*/

    cout << " El valor de BOOK_ID_MAX es: " << BOOK_ID_MAX << endl;
    cout << "Define:" << MI_PRIMER_DEFINE << endl;

    //Ejemplo #5
    cout << "La cantidad de casas en el condominio es:" << CASA_MAX << endl;
    return 0;
}