CXX      = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

SRCS = $(wildcard *.cpp)
BINS = $(SRCS:.cpp=)

all: $(BINS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# make run T=A  →  compile A.cpp and run with stdin
run: $(T)
	./$(T)

clean:
	rm -f $(BINS)

.PHONY: all run clean
