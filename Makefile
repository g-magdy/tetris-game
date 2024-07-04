# Compiler
CXX = g++

# Compiler Flags
CXXFALGS = -Wall -Wextra -std=c++17

# Library directories
LIBS = -lraylib -lpthread -lm -ldl -lrt

# Include directories
INCLUDES = -Iinclude

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files (to optimize building)
OBJS = $(SRCS:.cpp=.o)

# The name of the executable project
TARGET = game

# Build rules
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFALGS) -o $(TARGET) $(OBJS) $(LIBS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)


.PHONY: all run clean