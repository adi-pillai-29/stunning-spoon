//Adi Pillai, arp3np@virginia.edu, 02/26/2021, "List.cpp"
#include <iostream>
#include "List.h"
using namespace std;

List::List(){
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;
}

List::List(const List& source){
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
  head = NULL;
  tail = NULL;
}

List& List::operator=(const List & source){
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
bool List::isEmpty() const{
  if(count == 0){
  return true;
  }
}
void List::makeEmpty(){
  ListItr currentItr(head-> next);
  for(int i = 0; i < count; i++){
    if(size() != 0){
      ListNode * currentNode = currentItr.current;
      currentNode -> previous->next = currentNode -> next;
      currentNode->next->previous = currentNode->previous;
      currentItr.current = currentItr.current->next;
      delete currentNode;
      currentNode = NULL;
    }
  }
  count = 0;
  head->next = tail;
  tail->previous = head;
}
ListItr List::first(){
  ListItr firstListItr(head->next);
  return firstListItr;
}
ListItr List::last(){
  ListItr lastListItr(tail->previous);
  return lastListItr;
}
void List::insertAfter(int x, ListItr position){
  ListNode * insertedAfter = new ListNode();
  position.current->next->previous  = insertedAfter;
  insertedAfter->next = position.current->next;
  position.current->next = insertedAfter;
  insertedAfter-> previous = position.current;
  insertedAfter -> value = x;
  count += 1;
}
void List::insertBefore(int x, ListItr position){
  ListNode * insertedBefore = new ListNode();
  position.current->previous->next = insertedBefore;
  insertedBefore->previous = position.current->previous->next;
  position.current->previous = insertedBefore;
  insertedBefore->next = position.current;
  insertedBefore->value = x;
  count += 1;
}
void List::insertAtTail(int x){
  ListNode* nodeAtTail = new ListNode();
  nodeAtTail->value = x;
  nodeAtTail->next = tail;
  nodeAtTail-> previous = tail -> previous;
  tail->previous->next = nodeAtTail;
  tail->previous = nodeAtTail;
  count += 1;
}
ListItr List::find(int x){
  ListItr foundNode(head -> next);
  for(int i = 0; i < count; i++){
    if(foundNode.current->value == x){
      return foundNode;
    }
    else{
      foundNode.moveForward();
    }
  }
}
void List::remove(int x){
  ListNode * currentNode = head -> next;
  for(int i = 0; i < count; i++){
    if(currentNode->value == x){
      currentNode->previous->next = currentNode->next;
      currentNode->next->previous = currentNode->previous;
      count -= 1;
      delete currentNode;
      currentNode = NULL;
      break;
    }
    else{
      currentNode = currentNode -> next;
    }
  }
}
  
int List::size() const{
  return count;
}

	      
					    

  


			       
			      
