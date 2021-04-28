//Adi Pillai, arp3np@virginia.edu, 04/26/2021, "heap.cpp"

//Redesigned based on instructor code for binary heap with integers
//Redesigned to create a minHeap with huffman node pointers

//Citation:
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "huffListNode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
  huffListNode* newNode = new huffListNode();
  heapHuff.push_back(newNode);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffListNode*> vec) : heap_size(vec.size()) {
    heapHuff = vec;
    heapHuff.push_back(heapHuff[0]);
    huffListNode* newNode = new huffListNode();
    heapHuff[0] = newNode;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
  if(!isEmpty()){
    for(huffListNode* i : heapHuff){
      delete i;
    }
    makeEmpty();
  }
}

void heap::insert(huffListNode* x) {
    // a vector push_back will resize as necessary
    heapHuff.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffListNode* x = heapHuff[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->frequency < heapHuff[hole/2]->frequency); hole /= 2) {
        heapHuff[hole] = heapHuff[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heapHuff[hole] = x;
}

huffListNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffListNode* ret = heapHuff[1];
    // move the last inserted position into the root
    heapHuff[1] = heapHuff[heap_size--];
    // make sure the vector knows that there is one less element
    heapHuff.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffListNode* x = heapHuff[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heapHuff[child+1]->frequency < heapHuff[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->frequency > heapHuff[child]->frequency) {
            heapHuff[hole] = heapHuff[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heapHuff[hole] = x;
}

huffListNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heapHuff[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapHuff.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}


