#Adi Pillai, arp3np@virginia.edu, 03/22/2021, "Makefile"
#Makefile for prelab 5

CXX = clang++ 
OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o

TreeCalc: $(OBJECTS)
	$(CXX) $(OBJECTS) 

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h


