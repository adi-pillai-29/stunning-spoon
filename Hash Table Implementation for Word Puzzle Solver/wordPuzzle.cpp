//Adi Pillai, arp3np@virginia.edu, 04/01/2021, "wordPuzzle.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"
#include "timer.h"
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols, bool &broken);

int main (int argc, char* argv[]){
  vector< vector<string> > outputVector;
  int rows;
  int dictSize = 0;
  int cols;
  bool broken;
  int wordCount = 0;
  string directions[] = {"N ", "NE", "E ", "SE", "S ", "SW", "W ", "NW"};
  ifstream file(argv[1]);
  if (!file.is_open()){
    return false;
  }
  while(!file.eof()){
    string s;
    file >> s;
    dictSize += 1;
  }
  file.close();
  hashTable* dictTable = new hashTable(dictSize);
  ifstream file2(argv[1]);
  if (!file2.is_open()){
    return false;
  }
  while(!file2.eof()){
    string s;
    file2 >> s;
    for(int i = 3; i <= s.length(); i++){
      if(i != s.length()){
	string s2 = s.substr(0,i);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	dictTable->insert(s2);
      } else {
	dictTable->insert(s.substr(0,i));
      }
    }
  }
  file2.close();
  bool result = readInGrid(argv[2], rows, cols);
  if (!result) {
    cout << "Error reading in file!" << endl;
    return 1;
  }
  timer t;
  t.start();
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      for(int k = 0; k < 8; k++){
  	for(int l = 3; l <= 22; l++){
	  string getWord = getWordInGrid(i, j, k, l, rows, cols, broken);
	  if(getWord.length() != NULL){
	    if((dictTable->find(getWord)) && getWord.length() >= 3){
	      wordCount += 1;
	      vector<string> stringVector{ directions[k], to_string(i), to_string(j), getWord};
	      outputVector.push_back(stringVector);
	    } else if(getWord.length() >= 3){
	      transform(getWord.begin(), getWord.end(), getWord.begin(), ::toupper);
	      
	      broken = !(dictTable->find(getWord));
	      if(broken == true){
		break;
	      }
	    }
	  }
	  if(broken == true){
	    break;
	  }
	}
	broken = false;
    }
   }
  }
  t.stop();
  for(int i = 0; i < outputVector.size(); i++){
    cout<<outputVector[i][0] << "(" << outputVector[i][1] << ", "<<outputVector[i][2]<<"):       "<<outputVector[i][3]<<endl;
  }
  cout<<wordCount<< " words found"<<endl;
  delete dictTable;
  return 0;
}
 
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
	// cout << endl;
    }
    return true;
}


string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols, bool& broken) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
      //if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
	  break;
        }
        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];
	
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
		if (r < 0) {
		  broken = true;
		}
                break; // north
            case 1:
                r--;
                c++;
		if (c >= numCols || r < 0) {
		  broken = true;
		}
                break; // north-east
            case 2:
                c++;
		if (c >= numCols) {
		  broken = true;
		}
                break; // east
            case 3:
                r++;
                c++;
		if (c >= numCols || r >= numRows) {
		  broken = true;
		}
                break; // south-east
            case 4:
                r++;
		if (r >= numRows) {
		  broken = true;
		}
                break; // south
            case 5:
                r++;
                c--;
		if (r >= numRows || c < 0) {
		  broken = true;
		}
                break; // south-west
            case 6:
                c--;
		if (c < 0) {
		  broken = true;
		}
                break; // west
            case 7:
                r--;
                c--;
		if (r < 0 || c < 0) {
		  broken = true;
		}
                break; // north-west
        }
    }
    return output;
}

