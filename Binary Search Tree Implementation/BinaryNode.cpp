//Adi Pillai, arp3np@virginia.edu, 03/23/2021, "BinaryNode.cpp"
#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::BinaryNode(const string& x){
  value = x;
  left = NULL;
  right = NULL;
}


BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
