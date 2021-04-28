//Adi Pillai, arp3np@virginia.edu, 04/27/2021, "huffmandec.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include "huffListNode.h"
#include <string>
using namespace std;


huffListNode* huffmanTreeBuilder(huffListNode* &root, string toInsert, string character2);
char huffTreeTraversal(huffListNode* tree, string &toDecode);
// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    unordered_map<string, string> mapping;
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        
        mapping[character] = prefix;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // close the file before exiting

    file.close();
    
    huffListNode* root = new huffListNode();
    string allbitscopy = allbits;
    for(auto x : mapping){
      root = huffmanTreeBuilder(root, x.second, x.first);
    }

    string output = "";
    while(allbitscopy.length() != 0){
      output += huffTreeTraversal(root, allbitscopy);
    }
    cout << output << endl;

    delete root;
      
    return 0;
}

char huffTreeTraversal(huffListNode* tree, string &toDecode){
  if(toDecode[0] == ' '){
    toDecode = toDecode.substr(1,toDecode.length()-1);
  }
  if(tree != NULL){
    if(tree->left == NULL && tree->right == NULL){
      return tree->letter;
    } else if(toDecode[0] == '0'){
      if(tree->left != NULL){
	toDecode = toDecode.substr(1,toDecode.length()-1);
	return huffTreeTraversal(tree->left, toDecode);
      }
    } else if(toDecode[0] == '1'){
      if(tree->right != NULL){
	toDecode = toDecode.substr(1,toDecode.length()-1);
	return huffTreeTraversal(tree->right, toDecode);
      }
    }
  }
}

huffListNode* huffmanTreeBuilder(huffListNode* &root, string toInsert, string character2){
  if(root != NULL){
    if(toInsert[0] == '0'){
	if(root->left == NULL){
	  huffListNode* zeroNode = new huffListNode();
	  if(toInsert.length() == 1){
	    root->left = zeroNode;
	    char leafChar = character2[0];
	    root->left->letter = leafChar;
	    return root;
	  }
          root->left = huffmanTreeBuilder(zeroNode, toInsert.substr(1,toInsert.length()-1), character2);
	  return root;
	} else if (root->left != NULL){
	  root->left = huffmanTreeBuilder(root->left, toInsert.substr(1,toInsert.length()-1), character2);
	  return root;
	}
      } else if(toInsert[0] == '1'){
	if(root->right == NULL){
	  huffListNode* oneNode = new huffListNode();
	  if(toInsert.length() == 1){
	    root->right = oneNode;
	    char leafChar2 = character2[0];
	    root->right->letter = leafChar2;
	    return root;
	  }
	  root->right = huffmanTreeBuilder(oneNode, toInsert.substr(1,toInsert.length()-1), character2);
	  return root;
	} else if(root->left != NULL){
	  root->right = huffmanTreeBuilder(root->right, toInsert.substr(1,toInsert.length()-1), character2);
	  return root;
	}
    }
  }
}
