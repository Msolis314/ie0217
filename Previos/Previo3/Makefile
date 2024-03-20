
CXX := g++
# Flags
CXXFLAGS :=  -Wall


SRCDIR := src

BINDIR := bin

# Listar todos los archivos .cpp en el directorio src excepto sum.cpp y main.cpp
SRCS := $(filter-out $(SRCDIR)/sum.cpp $(SRCDIR)/main.cpp,$(wildcard $(SRCDIR)/*.cpp))

EXECS := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%,$(SRCS))


all: $(EXECS) $(BINDIR)/sum_main


$(BINDIR)/%: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Para compilar sum_main que necesita sum.cpp y main.cpp
$(BINDIR)/sum_main: $(SRCDIR)/sum.cpp $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	rm -f $(EXECS) $(BINDIR)/sum_main
