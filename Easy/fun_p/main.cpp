#include <iostream>
#include "sol.h"
#include "sol2.h"
#include "sol3.h"

int main() {
  Solution3 sol;
  vector<int> nums = {3,5,10,1,7,12};
  int a = sol.maxdif(nums);
  std::cout << a << std::endl;
  return 0;
}
