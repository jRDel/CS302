TARGET = test6
HEADERS = config.h Stack.h StackLinked.h StackArray.h
SRCS = test6.cpp StackLinked.cpp StackArray.cpp
OBJECTS := $(patsubst %.cpp, %.o, $(SRCS))
CXX = g++
CXX_FLAGS = -Wall -std=c++11

.PHONY: default all clean

all: test6 $(TARGET)

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
