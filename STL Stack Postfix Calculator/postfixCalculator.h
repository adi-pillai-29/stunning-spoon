//Adi Pillai, arp3np@virginia.edu, 02/28/2021, "postfixCalculator.h"
#ifndef POSTFIXCALC_H
#define POSTFIXCALC_H

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std;

class postfixCalculator {
public:
  postfixCalculator();
  void calculator();
  std::stack<int> stackOfInts;
  std::string operation;
};
#endif
