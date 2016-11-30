#include <iostream>

class Solution {
public:
  bool isPowerOfTwo(int n) {
    // 2^n ? bitwise is easy
    if(n <= 0){
      return false;
    }
    else{
      if((n & (n-1)) == 0){
        return true;
      }

      return false;
    }

  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}