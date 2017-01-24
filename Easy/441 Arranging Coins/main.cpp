#include <iostream>
class Solution{
public:
  int arrangeCoins(int n){
    int cur = 1;
    int remainder = n - cur;
    while(remainder >= cur + 1){
      cur++;
      remainder -= cur;
    }
    return n == 0 ? 0 : cur;
  }
};
int main() {
  Solution test;
  std::cout << test.arrangeCoins(3) << std::endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}