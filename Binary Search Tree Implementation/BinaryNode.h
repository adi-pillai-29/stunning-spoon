//Adi Pillai, arp3np@virginia.edu, 03/23/2021, "BinaryNode.h"
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
    BinaryNode(const string& x);
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
