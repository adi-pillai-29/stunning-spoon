//Adi Pillai, arp3np@virginia.edu, 03/26/2021, "AVLNode.cpp"
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
    changeHeight = false;
}

AVLNode::AVLNode(const string& x) {
    value = x;
    left = NULL;
    right = NULL;
    height = 0;
    changeHeight = false;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
