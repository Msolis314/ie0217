#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include <string>

class TextProcessor {
    private:
        //Atributos de la clase
        std::string input_filename;
        std::string output_filename;
    public:
    //Se utiliza const en elparametro para no modificarlo y optimizar compilacion
        TextProcessor(const std::string& input_filename, const std::string& output_filename);
        //Funcion para reemplazar el patron
        void replace(const std::string& search_pattern, const std::string& replace_string);

};
#endif // TEXT_PROCESSOR_HPP