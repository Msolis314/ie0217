CXX := g++
# Flags
CXXFLAGS :=  -Wall


SRCDIR := src

BINDIR := bin

# Listar todos los archivos .cpp en el directorio src excepto persona.cpp , main.cpp, main_ejercicio.cpp y ejercicio.cpp
SRCS := $(filter-out $(SRCDIR)/persona.cpp $(SRCDIR)/main.cpp $(SRCDIR)/main_ejercicio.cpp $(SRCDIR)/ejercicio.cpp,$(wildcard $(SRCDIR)/*.cpp))

EXECS := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%,$(SRCS))


all: $(EXECS) $(BINDIR)/main


$(BINDIR)/%: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Para compilar main que necesita persona.cpp y main.cpp
$(BINDIR)/main: $(SRCDIR)/persona.cpp $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

all: $(EXECS) $(BINDIR)/main_ejercicio
# Para compilar ejercicio_main que necesita ejercicio.cpp y main_ejercicio.cpp
$(BINDIR)/main_ejercicio: $(SRCDIR)/ejercicio.cpp $(SRCDIR)/main_ejercicio.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXECS) $(BINDIR)/main