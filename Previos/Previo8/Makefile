CXX := g++
# Flags
CXXFLAGS :=  -Wall


SRCDIR := src

BINDIR := bin

SRCS := $(wildcard $(SRCDIR)/*.cpp)

EXECS := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%,$(SRCS))

all: $(EXECS)

$(BINDIR)/%: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXECS)

.PHONY: all clean