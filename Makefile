SFML_PATH = ./SFML

# Compiler and Flags
CXX = g++

CXXFLAGS = -Wall -std=c++14 -O2 -I"$(SFML_PATH)/include" -I"./include"

# Libraries
LIBS = -L"$(SFML_PATH)/lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Target Executable Name
TARGET = project

# Source and Object Files
SRCS = $(wildcard *.cpp) $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Main build rule
all: $(TARGET)

# Linking 
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

# Compiling 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean command
clean:
	del /Q *.o $(TARGET).exe