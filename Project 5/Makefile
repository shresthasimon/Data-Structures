TARGET = queue
LIBS = -lm  
HEADERS =  Queue.h QueueArray.h QueueLinked.h config.h#List of all header files
SRCS = test7.cpp QueueArray.cpp QueueLinked.cpp #List of all source files
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))  
CXX = g++ 
CXX_FLAGS = -Wall -std=c++11 -g 


.PHONY: default all clean


all: $(TARGET)


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@


clean:
	-rm -f *.o
	-rm -f $(TARGET)
