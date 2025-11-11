CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
OUT = SistemaGestionHospital

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $@

clean:
	rm -f src/*.o $(OUT)
