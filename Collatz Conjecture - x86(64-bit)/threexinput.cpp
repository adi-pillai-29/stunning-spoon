//Adi Pillai, arp3np@virginia.edu, 04/19/2021, "threexinput.cpp"
#include <iostream>
//#include "timer.h"

using namespace std;

extern "C" int threexplusone(int x);

int main(){
  int x;
  //double avgTime = 0.0;
  int n;
  int result;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;
  result = threexplusone(x);
  //timer t;
  for(int i = 0; i < n; i+=10){
    //t.start();
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    threexplusone(x);
    //t.stop();
    //avgTime += t.getTime();
  }
  //avgTime = avgTime / n;
  //cout << "Time: " << avgTime << endl;
  cout << "Steps: " << result << endl;
  return 0;
}
  
  
