CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fopenmp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = tinyphysics

$(TARGET): main/space.cpp src/element.cpp src/environment.cpp
	$(CXX) $(CXXFLAGS) main/space.cpp src/element.cpp src/environment.cpp -o $(TARGET) $(LIBS) 

run:
	./tinyphysics	

clean:
	rm -f $(TARGET)