
# FLAGS
CXX = g++
CXXFLAGS = -std=c++11 -Wall

#Directorios
SRCDIR = src
OUTDIR = bin

#Se hace la sustitución de los archivos .cpp por los .o
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SOURCES:$(SRCDIR)/%.cpp=$(OUTDIR)/%.o)

#Ejecutable
EXEC = tarea5.x

#Targer principal
#Primero se compila y luego se ejecuta
all: build run

#Target para el ejecutable
build: $(EXEC)

#Regla explicita para crear el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Regla implícita para compilar los archivos .cpp
$(OUTDIR)/%.o: $(SRCDIR)/%.cpp | $(OUTDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Regla correr el ejecutable

.PHONY: run
run: 
	./$(EXEC)


#Regla para limpiar el directorio
clean:
	$(RM) -r $(OUTDIR)
.PHONY: clean