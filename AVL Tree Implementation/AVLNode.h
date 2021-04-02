//Adi Pillai, arp3np@virginia.edu, 03/26/2021, "AVLNode.h"
#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
    AVLNode(const string& x);
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;
    bool changeHeight;
    friend class AVLTree;
};

#endif
