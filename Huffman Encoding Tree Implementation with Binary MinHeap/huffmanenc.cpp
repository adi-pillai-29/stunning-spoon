//Adi Pillai, arp3np@virginia.edu, 04/26/2021, "huffmanenc.cpp"

//relies on instructor code from "fileio.cpp" for C++ I/O
//relies on instructor code in order to construct the minHeap using huffman node pointers in "heap.h" and "heap.cpp"

//heap code in:
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository


// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include "huffListNode.h"
#include "heap.h"

using namespace std;


huffListNode* huffTreeBuilder(heap* minHeap);
unordered_map<char, string> huffTreeTraversal(huffListNode* huffTree, string binary);

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    unordered_map<char, int> freq;

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
      if(isprint((int) g)){
        freq[g] = 0;
      }
    }
    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    int current_count;
    // Read the file again, and print to the screen
    while (file.get(g)) {
      if(freq.find(g) != freq.end()){
	current_count = freq[g];
	freq[g] = current_count + 1;
      }
    }

    int numElements = 0;
    double sum = 0;
    for(auto x : freq){
      numElements += 1;
      sum += x.second;
    }

    heap* minHeap = new heap();
   
    for(auto x : freq){
      huffListNode* newNode = new huffListNode();
      newNode->letter = x.first;
      newNode->frequency = x.second;
      newNode->left = NULL;
      newNode->right = NULL;
      minHeap->insert(newNode);
    }


    huffListNode* huffTree = huffTreeBuilder(minHeap);
    
    unordered_map<char, string> encoding = huffTreeTraversal(huffTree, ""); 

    for(auto y : encoding){
      if(y.first == ' '){
	cout << "space" << " " << y.second << endl;
      } else {
        cout << y.first << " " << y.second << endl;
      }
    }

    
    cout << "----------------------------------------" << endl;


    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);
    // Read the file again, and print to the screen

    char h;
    double sum2 = 0;
    while (file.get(h)) {
      cout << encoding[h] << " ";
      sum2 += encoding[h].length();
      if(h == ' '){
	cout << endl;
      }
    }
    cout<<endl;

    // close the file
    file.close();

    double cmprRat = (8*sum)/(sum2);
    stringstream tmp;
    tmp << setprecision(5) << fixed << cmprRat;
    double newCmprRat = stod(tmp.str());
    
    double cost = sum2/sum;
    stringstream tmp2;
    tmp2 << setprecision(5) << fixed << cost;
    double newCost = stod(tmp2.str());
    
    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << sum << " symbols that are encoded." << endl;
    cout << "There are " << numElements << " distinct symbols used." << endl;
    cout << "There were " << 8*sum << " bits in the original file." << endl;
    cout << "There were " << sum2 << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << newCmprRat << "." << endl;
    cout << "The cost of the Huffman tree is "<< newCost << " bits per character." << endl;

    delete minHeap;
    
    return 0;   
}

huffListNode* huffTreeBuilder(heap* minHeap){
  while(minHeap->heap_size != 1){
    huffListNode* parent = new huffListNode();
    parent->left = minHeap->deleteMin();
    parent->right = minHeap->deleteMin();
    parent->frequency = parent->left->frequency + parent->right->frequency;
    parent->letter = NULL;
    minHeap->insert(parent);
  }
  return minHeap->findMin();

}

unordered_map<char, string> huffTreeTraversal(huffListNode* huffTree, string binary){
  string binary2 = binary;
  unordered_map<char, string> encoding1;
  unordered_map<char, string> encoding2;
  if(huffTree != NULL){
    if (huffTree->right == NULL && huffTree->left == NULL){
      unordered_map<char, string> encoding;
        encoding[huffTree->letter] = binary;
	return encoding; 
    } if(huffTree->left != NULL){
      binary += "0";
       encoding1 = huffTreeTraversal(huffTree->left, binary);    
    } if(huffTree->right != NULL){
      binary2 += "1";
      encoding2 = huffTreeTraversal(huffTree->right, binary2);
    }
    for(auto x : encoding2){
      encoding1.insert(x);
    }
    return encoding1;
  }
}
