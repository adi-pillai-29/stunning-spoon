#Adi Pillai, arp3np@virginia.edu, 04/27/2021, "Makefile"                       
#Makefile for inlab10

CXX = clang++ $(CXX_FLAGS)
CXX_FLAGS = -Wall -g -O2
OBJECTS = huffmandec.o huffListNode.o 

huffmandec: $(OBJECTS)
	$(CXX) $(OBJECTS)


huffListNode.o: huffListNode.cpp huffListNode.h
huffmandec.o: huffmandec.cpp huffListNode.h 

