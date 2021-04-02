//Adi Pillai, arp3np@virginia.edu, 03/04/2021, "Stack.cpp"

#include "Stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

Stack::Stack(){
  listForStack = new List();
}
Stack::~Stack(){
  delete listForStack;
  listForStack = NULL;
}
void Stack::push(int e){
  //inserting at the top of the stack
  listForStack -> insertAtTail(e); 
}
int Stack::top(){
  ListItr toBeTopped = listForStack->last();
  int toppedValue = toBeTopped.retrieve();
  return toppedValue;
}
void Stack::pop(){
  ListItr toBePopped = listForStack->last();
  int poppedValue = toBePopped.retrieve();
  listForStack -> remove(poppedValue);
  
}
bool Stack::empty(){
  if(listForStack->isEmpty()){
    return true;
  } else {
    return false;
  }
}

