TARGET = main
HEADERS = MergeSort.h SelectionSort.h
SRCS = main.cpp MergeSort.cpp SelectionSort.cpp
OBJECTS := $(patsubst %.cpp, %.o, $(SRCS))
CXX = g++
CXX_FLAGS = -Wall -std=c++11

.PHONY: default all clean

all: main $(TARGET)

#Rules to recompile template headers when they change
#depend: .depend
#.depend: $(HEADERS)
	#rm -f ./.depend
	#$(CXX) $(CXX_FLAGS) -MM $^ > ./.depend;
#include .depend

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@
	
$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@
	
clean:
	-rm -f *.o
	-rm -f ./.depend
	-rm -f $(TARGET)
