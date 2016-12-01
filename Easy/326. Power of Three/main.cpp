#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    //First method: keep on divide three, the final remainder should be 1
    /*if (n < 1){return false;}
    if(n == 1){return true;}
    else{
      if(n%3 != 0){ return false;}
      n = n/3;
      return isPowerOfThree(n);
    }
     */

    //Second method: if n is power of 3, then log3(n) should be integer
    //log3(n) = log10(n)/log(10)3 = lg(n)/lg(3), cpp can only do base e, 2, 10;
    //how to check whether a is integer "a - int(a) = 0"

     if(n > 0 && log10(n)/log10(3) - int(log10(n)/log10(3)) == 0){return true;}

     return false;


    /**
    return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    */

  }
};

int main() {
  Solution test;
  int n = 9;
  cout << "the integer number of " << n << " power of 3 is " << test.isPowerOfThree(n) << endl;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}