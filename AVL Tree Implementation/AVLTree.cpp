//Adi Pillai, arp3np@virginia.edu, 03/26/2021, "AVLTree.cpp"
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>

using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
     root = insert(root, x);
}

AVLNode* AVLTree:: insert(AVLNode*& node, const string& x){
  if(node != NULL){ 
    if(node->value.compare(x) < 0){
      if(node->right == NULL){
	AVLNode* newNode = new AVLNode(x);
	node->right = newNode;
	if(node->left == NULL){
	  node->height += 1;
	  node->changeHeight = true;
	}
	return node;
      } else {
        insert(node->right, x);
	if(node->right->changeHeight == true){
	if(node->left != NULL){
	  if(node->right->height > node->left->height){
	    node->height += 1;
	    node->changeHeight = true;
	    node->right->changeHeight = false;
	  }
	} else {
	  node->height += 1;
	  node -> changeHeight = true;
	  node->right->changeHeight = false;
	}
	}
	balance(node);
        return node;
      }
    } else if(node->value.compare(x) > 0){
      if(node->left == NULL){
	AVLNode* newNode = new AVLNode(x);
	node->left = newNode;
	if(node->right == NULL){
	  node->height += 1;
	  node->changeHeight = true;
	}
	return node;
      } else {
        insert(node->left, x);
      if(node->left->changeHeight == true){
	if(node->right != NULL){
	  if(node->left->height > node->right->height){
	    node->height += 1;
	    node->changeHeight = true;
	    node->left->changeHeight = false;
	  }
      } else {
	  node->height += 1;
	  node->changeHeight = true;
	  node->left->changeHeight = false;
	}
      }   
	balance(node);
	return node;
      }
    }
  } else if (node == NULL) {
    AVLNode* newRootNode = new AVLNode(x);
    return newRootNode;
  }
  return node;
}



// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  return pathTo(root, x);
}


string AVLTree::pathTo(AVLNode*& n, const string& x){
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
bool AVLTree::find(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    return find(root, x);
}


bool AVLTree::find(AVLNode*& n, const string& x){
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
int AVLTree::numNodes(){
    // YOUR IMPLEMENTATION GOES HERE
    return numNodes(root);
}


int AVLTree::numNodes(AVLNode*& n){
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



// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  if(n->right != NULL && n->left != NULL){
    if(n->right->height - n->left->height == 2){
	if(n->right->right != NULL && n->right->left != NULL){	
	  if(n->right->right->height - n->right->left->height < 0){
	    // n->right->left = rotateLeft(n->right->left);
	    n->right = rotateRight(n->right);
	  } else if(n->right->right == NULL && n->right->left != NULL){
	    // n->right->left = rotateLeft(n->right->left);
	    n->right = rotateRight(n->right);
	  }
	}
	n = rotateLeft(n);
    } else if(n->right->height - n->left->height == -2){
	  if(n->left->right != NULL && n->left->left != NULL){	
	    if(n->left->right->height - n->left->left->height > 0){
	      //n->left->right = rotateRight(n->left->right);
	      n->left = rotateLeft(n->left);
	    } else if(n->left->right != NULL && n->left->left == NULL){
	      if(n->left->right->height == 2){        
		// n->left->right = rotateRight(n->left->right);
	        n->left = rotateLeft(n->left);
	      }
	    }
	  }
	  n = rotateRight(n);
    }
 } else if(n->left == NULL && n->right != NULL){
	  if(n->right->left != NULL){
	    n->right = rotateRight(n->right);
	  }
	n = rotateLeft(n);
  } else if(n->right == NULL && n->left != NULL){
	    if(n->left->right != NULL){
	      n->left = rotateLeft(n->left);
	  }
	n = rotateRight(n);    
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode* t;
  t = n->right;
  n->right = n->right->left;
  t->left = n;
  
  if((n->right != NULL && n->left != NULL)){
    n->height = max(n->right->height + 1, n->left->height + 1);
  } else if((n->right != NULL && n->left == NULL)){
    n->height = n->right->height + 1;
  } else if((n->left != NULL && n->right == NULL)){
    n->height = n->left->height + 1;  
  } else{
    n->height = 0;
  }

  if((t->right != NULL && t->left != NULL)){
    t->height = max(t->right->height + 1, t->left->height + 1);
  } else if((t->right != NULL && t->left == NULL)){
    t->height = t->right->height + 1;
  } else if((t->left != NULL && t->right == NULL)){
    t->height = t->left->height + 1;  
  }

  return t;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  AVLNode* t;
  t = n->left;
  n->left = n->left->right;
  t->right = n;
    if(n->right != NULL && n->left != NULL){
    n->height = max(n->right->height + 1, n->left->height + 1);
  } else if(n->right != NULL && n->left == NULL){
    n->height = n->right->height + 1;
  } else if(n->left != NULL && n->right == NULL){
    n->height = n->left->height + 1;
  } else{
    n->height = 0;
  }
    
   if(t->right != NULL && t->left != NULL){
    t->height = max(t->right->height + 1, t->left->height + 1);
  } else if(t->right != NULL && t->left == NULL){
    t->height = t->right->height + 1;
  } else if(t->left != NULL && t->right == NULL){
    t->height = t->left->height + 1;
  } 

    
  return t;
}
  

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
