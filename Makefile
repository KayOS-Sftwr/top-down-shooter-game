SFML_PATH = ./SFML


#complier
CXX = g++
CXXFLAGS = -Wall -std=c++14 -O2


LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Çıktı Alınacak Oyunun Adı
TARGET = project


SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)

# (Linking) 
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

#  (Compiling) 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	del /Q *.o $(TARGET).exe