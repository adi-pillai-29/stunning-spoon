//Adi Pillai, arp3np@virginia.edu, 03/04/2021, "postfixCalculator.cpp"
#include "postfixCalculator.h"
#include "Stack.h"

#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

postfixCalculator::postfixCalculator(){
  stackOfInts = new Stack();
  operation = "";
}
postfixCalculator::~postfixCalculator(){;
  delete stackOfInts;
  stackOfInts = NULL;
}
void postfixCalculator::calculator() {
  int answer;
  int firstOperand;
  int secondOperand; 
  if(stackOfInts->empty() == false){
     secondOperand = stackOfInts->top();
     stackOfInts->pop();
  } else {
     cout << "stack is empty"<< endl;
     exit(-1);
  }
  if(operation != "~"){
    if(stackOfInts->empty() == false){
      firstOperand = stackOfInts->top();
      stackOfInts->pop();
    } else {
      cout << "stack is empty"<< endl;
      exit(-1);
    }
  }
  if(operation == "+"){
     answer = firstOperand + secondOperand;
     stackOfInts->push(answer);
  } else if(operation == "-"){
     answer = firstOperand - secondOperand;
     stackOfInts->push(answer);
  } else if(operation == "*"){
    answer = firstOperand * secondOperand;
    stackOfInts->push(answer);
  } else if(operation == "/"){
    answer = firstOperand / secondOperand;
    stackOfInts->push(answer);
  } else if(operation == "~"){
    answer = secondOperand * -1;
    stackOfInts->push(answer);
  }
}
