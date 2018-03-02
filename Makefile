
CXXFLAGS=--std=c++14 -g -Wall
CC=g++-4.9
EXE=house
SRC=src/*.cpp
HEADERS=$(wildcard src/*.h)
OBJ= $(patsubst %.cpp, %.o, $(wildcard $(SRC)))
LDFLAGS=-lpthread

default: $(EXE)
all: default

$(EXE): $(OBJ)
	$(CC) $(OBJ) -Wall $(LDFLAGS) -o $@ 

%.o :%.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean: 
	rm $(EXE) $(OBJ)
