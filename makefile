
# Author: Kyle Wollman
# Date: 1/18/2017
# Project 1 makefile
  
CXX = g++
CXXFLAGS = -std=c++0x
OBJS = LangtonsAntMain.o board.o ant.o menu.o
SRCS = LangtonsAntMain.cpp board.cpp ant.cpp menu.cpp
HEADERS = board.hpp ant.hpp menu.hpp

all : $(OBJS)
	$(CXX) $(OBJS) -o project1 

$(OBJS) : $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean: 
	rm *.o project1
