CXX = g++
CXXFLAGS = -std=c++17 -fopenmp -Isrc

SRC = src/main.cpp \
      src/matrix_algorithms/traditional.cpp \
      src/matrix_algorithms/divide_and_conquer.cpp \
      src/matrix_algorithms/strassen.cpp \
      src/utils/performance_utils.cpp \
      src/utils/array_utils.cpp

OBJ = $(SRC:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o