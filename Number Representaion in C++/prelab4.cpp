//Adi Pillai, arp3np@virginia.edu, 03/14/2021, "prelab4.cpp"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);

int main() {
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}

void sizeOfTest(){
   cout << "Size of int: " << sizeof(int) << endl;
   cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
   cout << "Size of float: " << sizeof(float) << endl;
   cout << "Size of double: " << sizeof(double) << endl;
   cout << "Size of char: " << sizeof(char) << endl;
   cout << "Size of bool: " << sizeof(bool) << endl;
   cout << "Size of int*: " << sizeof(int*) << endl;
   cout << "Size of char*: " << sizeof(char*) << endl;
   cout << "Size of double*: " << sizeof(double*) << endl; 
}

void overflow(){
  unsigned int x = 4294967295;
  cout << x << " + 1 = " << (x+1) << endl;
}

void outputBinary(unsigned int x){
  bool zeroResult = false;
  std::string binaryOutput = "00000000000000000000000000000000";
  double maxPwrTwo = 0.0;
  const char *a = "1";
  while((std::pow(2.0, maxPwrTwo) <= double(x)) && (x != 0)){
    if(std::pow(2.0, maxPwrTwo + 1) <= double(x)){
      maxPwrTwo = maxPwrTwo + 1;
    } else {
      break;
    }
  }
  while(zeroResult == false && (x != 0)){
    if((double(x) - std::pow(2.0, maxPwrTwo)) == 0.0){
      binaryOutput[int(maxPwrTwo)] = *a;
      zeroResult = true;
    } else if (std::pow(2.0, maxPwrTwo) < double(x)) {
      x -= (unsigned int)(std::pow(2.0, maxPwrTwo));
      binaryOutput[maxPwrTwo] = *a;
    }
    maxPwrTwo -= 1;
  }
  binaryOutput.insert(4, " ");
  binaryOutput.insert(9, " ");
  binaryOutput.insert(14, " ");
  binaryOutput.insert(19, " ");
  binaryOutput.insert(24, " ");
  binaryOutput.insert(29, " ");
  binaryOutput.insert(34, " ");
  int len = binaryOutput.length();
  int n = len - 1;
  for(int i = 0; i < (len/2); i++){
    swap(binaryOutput[i], binaryOutput[n]);
    n = n-1;
  }
  cout<< binaryOutput << endl;
}
