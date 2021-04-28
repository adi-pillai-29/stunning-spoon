//Adi Pillai, arp3np@virginia.edu, 04/26/2021, "huffListNode.h"
#ifndef HUFFLISTNODE_H
#define HUFFLISTNODE_H

#include <string>
using namespace std;

class huffListNode {
public:
    huffListNode(); // Default Constructor
    ~huffListNode();
    char letter;
    int frequency;
    huffListNode* left;
    huffListNode* right;
};

#endif
