#ifndef LIBRO_HPP
#define LIBRO_HPP
#include <string>
#include <iostream>
#include <vector>

class Libro {
    public:
        std::string titulo;
        std::string autor;
        int anioPublicacion;

        Libro(std::string t,std::string a,int anio);
        bool operator<(const Libro& l) const;
};

#endif // LIBRO_HPP