CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = tinyphysics

$(TARGET): main/space.cpp
	$(CXX) $(CXXFLAGS) main/space.cpp -o $(TARGET) $(LIBS)

run:
	./tinyphysics	

clean:
	rm -f $(TARGET)