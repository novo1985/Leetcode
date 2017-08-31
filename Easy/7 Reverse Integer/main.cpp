#include <iostream>
using namespace std;

//assume input is 32-bit signed integer. caution: overflow & ending with 0
class Solution{
public:
  int reverse(int x){
    //last digit = x % 10; reminder digits = x / 10 (floor function)
    int res = 0; // if x = 0, just return 0;
    while(x != 0){
      if(res > INT32_MAX/10 || res < INT32_MIN/10){
        return 0;
      }
      res = res * 10 + x % 10;
      x = x / 10;
    }
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}