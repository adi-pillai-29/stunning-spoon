#Adi Pillai, arp3np@virginia.edu, 04/26/2021, "Makefile"                       
#Makefile for prelab10                                                          
CXX = clang++ $(CXX_FLAGS)
CXX_FLAGS = -Wall -g -O2
OBJECTS = huffmanenc.o huffListNode.o heap.o

huffmanenc: $(OBJECTS)
	$(CXX) $(OBJECTS)

heap.o: heap.cpp heap.h huffListNode.h
huffListNode.o: huffListNode.cpp huffListNode.h
huffmanenc.o: huffmanenc.cpp huffListNode.h heap.h


