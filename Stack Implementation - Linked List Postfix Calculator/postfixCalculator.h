//Adi Pillai, arp3np@virginia.edu, 03/04/2021, "postfixCalculator.h"
#ifndef POSTFIXCALC_H
#define POSTFIXCALC_H

#include "Stack.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class postfixCalculator {
public:
  postfixCalculator();
  ~postfixCalculator();
  void calculator();
  std::string operation;
  Stack* stackOfInts;
};
#endif
