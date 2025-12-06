# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -I include

# SFML library flags
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# For Windows with custom SFML path, uncomment and modify:
# SFML_INCLUDE = -I "C:/SFML-2.5.0/include"
# SFML_LIB = -L "C:/SFML-2.5.0/lib"
# SFML_FLAGS = $(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES = main.cpp \
          src/Animation.cpp \
          src/Entity.cpp \
          src/Player.cpp \
          src/Asteroid.cpp \
          src/Bullet.cpp \
          src/Globals.cpp \
          src/PowerUp.cpp \
          src/GameState.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Output executable
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(SFML_FLAGS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f main.exe

# Run the game
run: $(TARGET)
	./$(TARGET)

# Rebuild everything
rebuild: clean all

.PHONY: all clean run rebuild

