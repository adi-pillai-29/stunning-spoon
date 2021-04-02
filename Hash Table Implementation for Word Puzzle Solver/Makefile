#Adi Pillai, arp3np@virginia.edu, 04/01/2021, "Makefile"
#Makefile for prelab6

CXX = clang++ $(CXX_FLAGS)
CXX_FLAGS = -O2
OBJECTS = hashTable.cpp hashTable.h wordPuzzle.cpp timer.h timer.cpp

hashTable: $(OBJECTS)
	$(CXX) $(OBJECTS)

hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
