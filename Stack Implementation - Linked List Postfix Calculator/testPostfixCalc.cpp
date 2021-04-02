//Adi Pillai, arp3np@virginia.edu, 03/04/2021, "testPostfixCalc.cpp"

#include "postfixCalculator.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int main() {
  postfixCalculator * postfix  = new postfixCalculator();
  std::string inputTracker;
  while (cin >> inputTracker){
    if(inputTracker != "+" && inputTracker != "-" && inputTracker != "/" && inputTracker != "*" && inputTracker != "~"){
      postfix->stackOfInts->push(std::stoi(inputTracker));
    } else {
      postfix->operation = inputTracker;
      postfix->calculator();
    }
  }
  cout << postfix->stackOfInts->top() << endl;
  delete postfix;
  return 0;
}
