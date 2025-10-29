CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -Iinclude

TARGET = main
TARGET_TEST = target_test

SRC = $(wildcard src/*.cpp) main.cpp
HEADERS = $(wildcard include/*.h)

out: clean compile execute
compile: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

$(TARGET_TEST): tests/test.cpp $(wildcard src/*.cpp) $(HEADERS)
	$(CXX) $(CXXFLAGS) tests/test.cpp $(wildcard src/*.cpp) -o $(TARGET_TEST)

execute: $(TARGET)
	./$(TARGET)

test: $(TARGET_TEST)
	./$(TARGET_TEST)

clean:
	rm -f $(TARGET) $(TARGET_TEST)
	rm -rf $(TARGET).dSYM $(TARGET_TEST).dSYM