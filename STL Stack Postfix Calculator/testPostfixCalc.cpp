//Adi Pillai, arp3np@virginia.edu, 03/02/2021, "testPostfixCalc.cpp"
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

#include "postfixCalculator.h"

int main() {
  postfixCalculator * postfix  = new postfixCalculator();
  std::string inputTracker;
  while (cin >> inputTracker){
    if(inputTracker != "+" && inputTracker != "-" && inputTracker != "/" && inputTracker != "*" && inputTracker != "~"){
      postfix->stackOfInts.push(std::stoi(inputTracker));
    } else {
      postfix->operation = inputTracker;
      postfix->calculator();
    }
  }
  cout << postfix->stackOfInts.top() << endl;
  delete postfix;
  return 0;
}
