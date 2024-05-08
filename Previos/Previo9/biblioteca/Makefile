#Makefile para compilar un programa C++ con multiples archivos fuente y clases
#Nombre del programa de salida
TARGET = gestion_biblioteca.exe

#Objetivo predeterminado
#Por defecto, busca un archivo llamado "all" o el primer objetivo que encuentre
all: $(TARGET)

#Compilador de C++
CXX = g++

#Opciones de compilacion
CXXFLAGS = -Wall -std=c++11

#Lista de archivos fuente
SOURCES = main.cpp biblioteca.cpp libro.cpp

#Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe)

#Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXFLAGS) $(OBJECTS) -o $(TARGET)

#Regla para limpiar los archivos generados
.PHONY: clean
clean:
	del $(TARGET) $(OBJECTS)