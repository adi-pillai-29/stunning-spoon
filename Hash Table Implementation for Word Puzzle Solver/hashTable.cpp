//Adi Pillai, arp3np@virginia.edu, 04/01/2021, "hashTable.cpp"
#include <iostream>
#include "hashTable.h"

#include <stdio.h>
#include<ctype.h>
#include <math.h>
#include <string>
#include <locale>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
using namespace std;


bool hashTable::checkPrime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkPrime(++n) );
    return n; // all your primes are belong to us
}

hashTable::hashTable(int x){
  loadFactor = 0.75;
  tableSize = ceil(x / loadFactor);
  tableSize = getNextPrime((unsigned int) tableSize);
  hashVector.resize(tableSize);
  for(int i = 0; i<tableSize; i++){
    list<string> vectorElement;
    hashVector[i] = vectorElement;
  }
}


unsigned int hashTable::hashFunction(string key){
  double sum = 0;
  unsigned int output;
  double powers[22];
  powers[0] = 1;
  powers[1] = 37;
  powers[2] = 1369;
  powers[3] = 50653;
  powers[4] = 1874161;
  powers[5] = 69343957;
  powers[6] = 2565726409;
  powers[7] = 94931877133;
  powers[8] = 3512479453921;
  powers[9] = 129961739795077;
  powers[10] = 4808584372417849;
  powers[11] = 177917621779460400;
  powers[12] = 6582952005840036000;
  powers[13] = 2.43569224216081300000e20;
  powers[14] = 9.012061295995008e+21;
  powers[15] = 3.334462679518153e+23;
  powers[16] = 1.2337511914217166e+25;
  powers[17] = 4.5648794082603513e+26;
  powers[18] = 1.6890053810563301e+28;
  powers[19] = 6.249319909908421e+29;
  powers[20] = 2.3122483666661157e+31;
  powers[21] = 8.555318956664628e+32;
  for(int i = 0; i<key.length(); i++){
    sum += (double)(int(key[i])) * powers[i];
  }
  output = (unsigned int)(fmod(sum, (double) tableSize));
  return output;
}

bool hashTable::insert(string key){
  bool alnum = false;
  for(int i = 0; i<key.length(); i++){
    if(!isalpha(key[i])){
      alnum = true;
    }
  }
  if(!alnum){
    unsigned int position = hashFunction(key); 
    hashVector[position].push_back(key);
    return true;
  }
  return false;
}

bool hashTable::find(string key){
  unsigned int position = hashFunction(key); 
  list <string> :: iterator it;
  for(it = hashVector[position].begin(); it != hashVector[position].end(); ++it){
    if(*it == key){
      return true;
    }
  }
  return false;
}

int hashTable::calcAvg(){
  int sum = 0;
  int avg;
  for(int i = 0; i<tableSize; i++){
    sum += hashVector[i].size();
  }
  avg = sum / tableSize;
  return avg;
}
