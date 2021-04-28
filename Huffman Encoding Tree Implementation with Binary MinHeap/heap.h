//Adi Pillai, arp3np@virginia.edu, 04/26/2021, "heap.h"

//Redesigned based on instructor code for binary heap with integers
//Redesigned to create a minHeap with huffman node pointers

//Citation:
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository


#ifndef HEAP_H
#define HEAP_H
#include "huffListNode.h"
#include <vector>
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffListNode*> vec);
    ~heap();

    void insert(huffListNode* x);
    huffListNode* findMin();
    huffListNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    vector<huffListNode*> heapHuff;
    unsigned int heap_size;
    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
