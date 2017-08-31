#include <iostream>
using namespace std;

/* Reverse bits of a given 32 bits unsigned integer. */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t res = 0;
      uint32_t mask = 1;
      for(int i = 0; i <= 31; i++){
        if(mask & n){
          res = res + 1;
        }
        if(i != 31){
          res = res << 1;
        }
        mask = mask << 1;
      }

      return res;
    }
};