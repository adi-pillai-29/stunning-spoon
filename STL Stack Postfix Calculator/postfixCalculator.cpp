//Adi Pillai, arp3np@virginia.edu, 02/28/2021, "postfixCalculator.cpp"
#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator(){
  std::stack<int> first;
  stackOfInts = first;
  operation = "";
}
void postfixCalculator::calculator() {
  int answer;
  int firstOperand;
  int secondOperand; 
  if(stackOfInts.empty() == false){
     secondOperand = stackOfInts.top();
     stackOfInts.pop();
  } else {
     cout << "stack is empty"<< endl;
     exit(-1);
  } 
  if(stackOfInts.empty() == false){
     firstOperand = stackOfInts.top();
     stackOfInts.pop();
  } else {
     cout << "stack is empty"<< endl;
     exit(-1);
  }
  if(operation == "+"){
     answer = firstOperand + secondOperand;
     stackOfInts.push(answer);
  } else if(operation == "-"){
     answer = firstOperand - secondOperand;
     stackOfInts.push(answer);
  }
}
