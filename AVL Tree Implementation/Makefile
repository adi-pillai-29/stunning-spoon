#Adi Pillai, arp3np@virginia.edu, 03/26/2021, "Makefile"
#Makefile for postlab5

CXX = clang++
OBJECTS = AVLTree.cpp AVLTree.h AVLNode.cpp AVLNode.h AVLPathTest.cpp

AVLTree: $(Objects)
	$(CXX) $(OBJECTS)

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
