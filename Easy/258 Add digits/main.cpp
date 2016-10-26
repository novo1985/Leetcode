#include <iostream>
#include <cmath>
using namespace std;

/* Could you do it without any loop/recursion in O(1) runtime? */

class Solution {
public:
  int addDigits(int num) {
    int digitroot;
    digitroot = num - 9 * (floor((num-1) / 9));
    return digitroot;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}