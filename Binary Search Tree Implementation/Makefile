#Adi Pillai, arp3np@virginia.edu, 03/23/2021, "Makefile"
#Makefile for inlab 5

CXX = clang++
OBJECTS = BinarySearchTree.cpp BinarySearchTree.h BinaryNode.cpp BinaryNode.h BSTPathTest.cpp

BinarySearchTree: $(Objects)
	$(CXX) $(OBJECTS)

BinarySearchTree.o: BinaryNode.cpp BinaryNode.h
BinaryNode.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

