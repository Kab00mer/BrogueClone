# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Executable
TARGET = main

# Source Files
SRCS := $(wildcard *.cpp)

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile each .cpp into a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
