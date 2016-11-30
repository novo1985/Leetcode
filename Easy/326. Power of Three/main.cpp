#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    //First method: keep on divide three, the final remainder should be 1
    if (n < 1){return false;}
    if(n == 1){return true;}
    else{
      if(n%3 != 0){ return false;}
      n = n/3;
      return isPowerOfThree(n);
    }

  }
};

int main() {
  Solution test;
  int n = 6;
  cout << "the integer number of " << n << " power of 3 is " << test.isPowerOfThree(n) << endl;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}