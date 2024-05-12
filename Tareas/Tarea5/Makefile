CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCDIR = src
OUTDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SOURCES:$(SRCDIR)/%.cpp=$(OUTDIR)/%.o)

EXEC = tarea5.x

all: build run

build: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OUTDIR)/%.o: $(SRCDIR)/%.cpp | $(OUTDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: run
run: 
	./$(EXEC)

clean:
	$(RM) -r $(OUTDIR)
.PHONY: clean