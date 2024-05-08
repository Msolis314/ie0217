# Compiler
CXX := g++

# flags
CXXFLAGS := -std=c++11 -Wall 

# Source
SRCDIR := src

# Output 
OUTDIR := bin


SRCS := $(wildcard $(SRCDIR)/*.cpp)


OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OUTDIR)/%.o)

# Ejecutable
EXEC := matrix.exe


all: $(EXEC)


$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilacion
$(OUTDIR)/%.o: $(SRCDIR)/%.cpp | $(OUTDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTDIR):
	mkdir -p $(OUTDIR)

# Clean
clean:
	$(RM) -r $(OUTDIR)

.PHONY: all clean