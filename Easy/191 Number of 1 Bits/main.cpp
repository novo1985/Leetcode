#include <iostream>

class Solution{
public:
  int hammingWeight(uint32_t n){

    int temp = 0;
    int C = 1;
    int res = 0;
    for(int i = 0; i < 32; i++){
      temp =  (n >> i) & C;
      if (temp == 1){
        res++;
      }
    }
    return res;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}