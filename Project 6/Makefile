TARGET = BST
LIBS = -lm  
HEADERS =  BinaryNode.h BinaryNodeTree.h BinarySearchTree.h NotFoundException.h PrecondViolatedExcept.h #List of all header files
SRCS = main.cpp #List of all source files
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))  
CXX = g++ 
CXX_FLAGS = -Wall -std=c++14 -g


.PHONY: default all clean


all: $(TARGET)


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@


clean:
	-rm -f *.o
	-rm -f $(TARGET)
