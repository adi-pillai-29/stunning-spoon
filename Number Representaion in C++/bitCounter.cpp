//Adi Pillai, arp3np@virginia.edu, 03/18/2021, "bitCounter.cpp"
#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int binaryBitCounter(int n);
string baseConverter(string toConvert, int startBase, int endBase);

int main(int argc, char **argv){
  if(argc == 1){
    cout << "You must enter a number" << endl;
    exit(0);
  } else {
    int converted = stoi(argv[1]);
    cout << argv[1] << " has " << binaryBitCounter(converted) << " bit(s)"<< endl;
  }
  cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(argv[2], stoi(argv[3]), stoi(argv[4])) << " (base " << argv[4] << ")" << endl;
  return 0;
}

int binaryBitCounter(int n){
  if(n == 1){
    return 1;
  }
  else if((n % 2) == 0){
    return binaryBitCounter(n/2);
  }
  else if((n % 2) == 1){
    return 1 + binaryBitCounter(n/2);
  }
  return 0;
}

string baseConverter(string toConvert, int startBase, int endBase){
  int sumBaseTen = 0;
  int sumBaseTenCounter = 0;
  string endString = "";
  int len = toConvert.length();
  int n = len - 1;
  for(int i = 0; i < (len/2); i++){
    swap(toConvert[i], toConvert[n]);
    n -= 1;
  }
  for(int i = 0; i < toConvert.length(); i++){
    if(toConvert[i] - '0' > 9){
      sumBaseTen +=  pow(startBase, i) * ((toConvert[i] - '0') - 7);
    } else {
      sumBaseTen += pow(startBase, i) * (toConvert[i] - '0');
    }
  }
  if(endBase == 10){
    return to_string(sumBaseTen);
  } else {
    while(sumBaseTenCounter < 1){
      int remainder = sumBaseTen % endBase;
      if(remainder <= 9){
	endString += to_string(remainder);
      } else {
	endString += (char)(48 + remainder + 7);
      }
      sumBaseTen = sumBaseTen / endBase;
      if(sumBaseTen == 0){
	sumBaseTenCounter += 1;
      }
    }
    int len_two = endString.length();
    int n_two = len_two - 1;
    for(int i = 0; i < (len_two/2); i++){
      swap(endString[i], endString[n_two]);
      n_two -= 1;
    }
  }
  return endString;
}
