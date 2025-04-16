# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Executable name
TARGET = program

# Source files
SRCS = main.cpp calculator.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# The default target
all: $(TARGET)

# Rule to create the target from object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object and executable files
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to remove all build files and the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project from scratch
re: fclean all
