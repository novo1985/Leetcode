#include <iostream>

class Solution {
public:
  bool isUgly(int num) {
    if(num<=0){return false;}
    //if(num==1){return true;}
    // prime number problem
    while(num%2 == 0){
      num = num/2;
    }
    while(num%3 == 0){
      num = num/3;
    }
    while(num%5 == 0){
      num = num/5;
    }
    if(num == 1){
      return true;
    }
    return false;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}