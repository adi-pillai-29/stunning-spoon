//Adi Pillai, arp3np@virginia.edu, 04/26/2021, "huffListNode.cpp"
#include "huffListNode.h"

// Default Constructor - left and right are NULL, value '?'
huffListNode::huffListNode() {
  letter = NULL;
  frequency = NULL;
  left = NULL;
  right = NULL;
}

huffListNode::~huffListNode(){
  delete left;
  delete right;
}


