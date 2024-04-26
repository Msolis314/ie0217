#include <iostream>
#include <regex>

int main(){
    //aqui el compilador se encarga de inferir el tipo de dato
    //se necesita porque es un objeto regex
    auto const regex = std::regex("(my|your) regex");

    auto const myText = std::string("A piece of text that contains my regex.");
    //regex_search devuelve true si encuentra una coincidencia
    //recibe el texto y el objeto regex con la expresion regular
    bool const myTextContainsRegex = std::regex_search(myText, regex);

    auto const yourText = std::string("A piece of text that contains your regex.");
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    auto const theirText = std::string("A piece of text that contains their regex.");
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    std::cout << std::boolalpha
              <<  myTextContainsRegex << '\n'
              <<  yourTextContainsRegex << '\n'
              <<  theirTextContainsRegex << '\n';

    return 0;
}