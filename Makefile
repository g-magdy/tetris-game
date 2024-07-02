TARGET = game

SRCS = main.cpp Grid.cpp

CXX = g++

CXXFALGS = -lraylib -lpthread -lm -ldl -lrt

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) $(SRCS) $(CXXFALGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)


.PHONY: all run clean