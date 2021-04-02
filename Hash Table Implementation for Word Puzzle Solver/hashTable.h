//Adi Pillai, arp3np@virginia.edu, 04/01/2021, "hashTable.h"

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <math.h>
#include <string>
#include <locale>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

class hashTable {
 public:
  hashTable(int x);
  unsigned int hashFunction(string key);
  bool find(string key);
  bool insert(string key);
  int calcAvg();
  double loadFactor;
  int tableSize;
  int getNextPrime (unsigned int n);
  bool checkPrime(unsigned int p);

 private:
  vector< list<string> > hashVector;
};
#endif
