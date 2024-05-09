CXX = g++

#Flags de compilación
CXXFLAGS = -Wall -std=c++11

LDFLAGS = -lstdc++fs

#Directorio con archivos fuente
SRC_DIR = src

#Directoio con archivos objetos
BIN_DIR = bin

#Aqui se identifican los archivos fuente
#Terminación .cpp
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

#Se crea la regla para generar los archivos objetos
#Se reemplaza la terminación .cpp de los archivos identificados en SRC
# por .o, y se colocan en BIN
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.exe)

#Nombre del ejecutable
#Se coloca en BIN
EXECUTABLE = $(BIN_DIR)/textprocessor.exe

#Regla para generar el ejecutable
all: $(EXECUTABLE)

#Aqui se compila el ejecutable
#Es equivalente a g++ -Wall -std=c++11 src/*.cpp -o bin/textprocessor.exe
$(EXECUTABLE): $(OBJECTS)

	$(CXX) $(CXXFLAGS) $^ -o $@ 

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp

	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)

#Regla para limpiar los archivos generados
#Se utiliza phony para indicar que clean no es un archivo
.PHONY: clean

clean:

	del $(BIN_DIR)



