CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = threads
SRC = threads.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET).exe 2>nul || true

run: $(TARGET)
	./$(TARGET).exe

.PHONY: all clean run
