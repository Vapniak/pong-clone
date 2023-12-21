CXX = g++
CXXFLAGS = -O3 -Wall -Werror -Wno-unused-variable
LDFLAGS = -lSDL2 -lSDL2_ttf

SRC := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
DEP := $(patsubst %.cpp, %.d, $(SRC))
BIN = bin

.PHONY: all clean

all: dirs game

dirs:
	mkdir -p ./$(BIN)

run: all
	$(BIN)/game

game: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(BIN)/game $^

-include $(DEP)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MP -MMD -o $@ -c $<

clean:
	rm -rf $(BIN) $(OBJ) $(DEP)
