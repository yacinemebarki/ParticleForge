# ParticleForge

ParticleForge is a small 2D physics simulation built with **C++ and SFML**.

The project simulates physical elements affected by environmental parameters such as **gravity, wind, friction, and restitution**. Each element has its own weight, which is assigned when it is created. The goal is to build a simple physics engine from scratch and later use the project as a foundation for experimenting with **parallel programming and GPU acceleration**.

## Features

- 2D object physics simulation
- Gravity control
- Wind control
- Friction control
- Restitution control
- Interactive sliders for physics parameters
- Collision with the floor
- Pause and restart controls
- Real-time visualization using SFML
- Elements rendered as colored circles

## Technologies

### C++
The main programming language used for the project.

C++ is used to implement:

- Physics calculations
- Object and environment classes
- Collision detection
- Simulation logic
- User interaction
- Application structure

### SFML
[SFML](https://www.sfml-dev.org/) is used for the graphical part of the project.

It provides:

- Window management
- 2D rendering
- Shapes and colors
- Text rendering
- Mouse and keyboard events
- Graphics primitives

### Make
The project uses a **Makefile** to automate compilation.

The Makefile compiles the C++ source files and links the required SFML libraries.

## Project Structure

```
ParticleForge/
├── image/
├── include/
│   ├── element.hpp
│   └── environment.hpp
│
├── main/
│   └── space.cpp
│
├── src/
│   ├── element.cpp
│   └── environment.cpp
│
├── Makefile
└── README.md
```

## Physics
The simulation uses basic Newtonian mechanics.

### Gravity
Gravity is represented as a force:

```
F = m × g
```
The resulting acceleration is calculated from:

```
a = F / m
```
The simulation then updates the object's velocity and position over time.

### Wind
Wind applies a horizontal force to the object, affecting its horizontal acceleration and velocity.

### Restitution
Restitution controls how much velocity is preserved when the object collides with the floor.

For example:

```
restitution = 1.0  → perfectly elastic collision
restitution = 0.0  → no bounce
```

### Friction
Friction reduces the object's horizontal velocity over time.

## User Interface
ParticleForge provides an interactive control panel where the simulation parameters can be modified while the program is running.

Available parameters:

| Parameter | Description |
| --- | --- |
| Gravity | Controls downward acceleration |
| Wind | Controls horizontal force |
| Friction | Reduces horizontal velocity |
| Restitution | Controls the bounce after collision |
## Build and Run

### Requirements
You need:

- C++ compiler with C++17 support
- Make
- SFML
On Ubuntu/Pop!_OS, SFML can be installed with:

```
sudo apt install libsfml-dev
```

### Compile
Clone the repository and enter the project directory:

```
git clone https://github.com/yacinemebarki/ParticleForge.git
cd ParticleForge
```
Then compile:

```
make
```

### Run

```
make run
```

### Clean
To remove the compiled executable:

```
make clean
```

## Makefile
The project uses a simple Makefile to compile the application:

```
CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = tinyphysics

$(TARGET): main/space.cpp src/element.cpp src/environment.cpp
	$(CXX) $(CXXFLAGS) main/space.cpp src/element.cpp src/environment.cpp -o $(TARGET) $(LIBS)

run:
	./tinyphysics

clean:
	rm -f $(TARGET)
```

## Future Development
ParticleForge is also intended to be a learning project for **parallel programming**.

Future versions may explore:

- Multiple simulated objects
- CPU parallelization
- Multithreading
- SIMD/vectorization
- CUDA/GPU acceleration
- Parallel collision detection
- Large-scale particle simulations
- Performance benchmarking between sequential and parallel implementations
The long-term goal is to compare how the same physics workload behaves when executed sequentially, in parallel on the CPU, and eventually on the GPU.

## Project Goal
The main goal of ParticleForge is not to create a production-ready physics engine.

It is a hands-on project for learning how a physics simulation works internally and eventually understanding how computationally intensive simulations can be optimized using **parallel programming and GPU computing**. 
