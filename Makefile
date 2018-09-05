CC = gcc
CXX = g++
CFLAGS = -g -Wall -O -std=c++11
TARGET = test

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

SOURCES = $(wildcard *.c *.cpp)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) 

clean: 
	rm -f *.o test