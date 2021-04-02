//Adi Pillai, arp3np@virginia.edu, 03/23/2021, "BinarySearchTree.cpp"
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    root = insert(root, x);
}


BinaryNode* BinarySearchTree::insert(BinaryNode*& n, const string& x){
  if(n != NULL){ 
    if(n->value.compare(x) < 0){
      if(n->right == NULL){
	BinaryNode* newNode = new BinaryNode(x);
	n->right = newNode;
	return n;
      } else {
        n-> right = insert(n->right, x);
        return n;
      }
    } else if(n->value.compare(x) > 0){
      if(n->left == NULL){
	BinaryNode* newNode = new BinaryNode(x);
	n->left = newNode;
	return n;
      } else {
        n-> left = insert(n->left, x);
	return n;
      }
    }
  } else if (n == NULL) {
    BinaryNode* newRootNode = new BinaryNode(x);
    return newRootNode;
  }
  return n;
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x){
    // YOUR IMPLEMENTATION GOES HERE
  return pathTo(root, x);
}


string BinarySearchTree::pathTo(BinaryNode*& n, const string& x){
  string finalString = "";
  if(find(x)){		
   if(n != NULL){		
    if(n->value == x){
        return x;		     
    } else if (n->value.compare(x) < 0){
        if(n->right != NULL){
	  finalString += n->value;
	  return finalString + " " + pathTo(n->right, x);	     
        }						     
    } else if (n->value.compare(x) > 0){
        if(n->left != NULL){
	  finalString += n->value;		    
          return finalString + " " + pathTo(n->left, x);
       }						   
    }					
  }
 }
  return finalString;
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x){
    // YOUR IMPLEMENTATION GOES HERE
    return find(root, x);
}

bool BinarySearchTree::find(BinaryNode*& n, const string& x){
  if(n != NULL){		
    if(n->value == x){
        return true;		     
    } else if (n->value.compare(x) < 0){
        if(n->right != NULL){
	  return find(n->right, x);	     
        } else {
	  return false;
	}
    } else if (n->value.compare(x) > 0){
        if(n->left != NULL){		    
          return find(n->left, x);
	} else {
	  return false;
	}
    }					
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes(){
    // YOUR IMPLEMENTATION GOES HERE
    return numNodes(root);
}


int BinarySearchTree::numNodes(BinaryNode*& n){
  int counter = 0;
  if(n != NULL){
    if(n->left == NULL && n->right == NULL){
      counter += 1;
      return counter;
    }
    return numNodes(n->left) + numNodes(n->right) + 1;
  }
  return counter;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}



