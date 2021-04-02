//Adi Pillai, arp3np@virginia.edu, 03/04/2021, "Stack.h"
#ifndef STACK_H
#define STACK_H


#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

class Stack {
public:
  Stack();
   ~Stack();
  void push(int e);
  void pop();
  int top();
  bool empty();
  List* listForStack;
};
#endif
