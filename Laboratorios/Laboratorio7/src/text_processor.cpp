#include "text_processor.hpp"
#include <fstream>
#include <regex>

TextProcessor::TextProcessor(const std::string& input_filename, const std::string& output_filename)
    : input_filename(input_filename), output_filename(output_filename) {}

void TextProcessor::replace(const std::string& search_pattern,const std::string& replace_string){
    //Aqui se abre el archivo de entrada y salida
    std::ifstream input_file(input_filename);
    std::ofstream output_file(output_filename);
    //Para leer linea por linea
    std::string line;

    //Objeto regex para buscar el patron
    std::regex pattern(search_pattern);
    //Si estan abiertos los archivos
    if (input_file && output_file){

        //Se usa el metodo getline para leer linea por linea
        while (getline(input_file,line)){
            //Se reemplaza el patron por el string
            //Usando el metodo regex_replace
            //(line, el patron, el string por el que se reemplaza)
            std::string replaced = std::regex_replace(line,pattern,replace_string);
            output_file << replaced << "\n";
        }
    }
}