//Adi Pillai, arp3np@virginia.edu, 02/26/2021, "ListItr.cpp"
#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr(){
  current = NULL;   
}
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}
bool ListItr::isPastEnd() const {
  if(current->next == NULL){
    return true;
  } else {
    return false;
  }
}
bool ListItr::isPastBeginning() const{
  if(current->previous == NULL){
    return true;
  } else {
    return false;
  }
}
void ListItr::moveForward(){
    current = current->next;
}
void ListItr::moveBackward(){
    current = current->previous;
}
int ListItr::retrieve() const {
  return current->value;
}

void printList(List& source, bool forward){
  if(forward == true){
    ListItr begPrintItr = source.first();
    while(begPrintItr.isPastEnd() == false){
      cout << begPrintItr.retrieve() << " ";
      begPrintItr.moveForward();
    }
    cout << endl;
  }
  else {
    ListItr endPrintItr = source.last();
    while(endPrintItr.isPastBeginning() == false){
      cout << endPrintItr.retrieve() << " ";
      endPrintItr.moveBackward();
    }
  cout << endl;
  }
}

   
