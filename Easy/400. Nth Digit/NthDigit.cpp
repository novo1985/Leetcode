#include <iostream>
using namespace std;

/* Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n < 231). ******/


/* 9:    1-9
 * 90:   10-99
 * 900:  100-999
 * 9000: 1000-9999
 * ...   ...       ****/

class Solution {
public:
    int findNthDigit(int n) {
      // we need find the location of n
      uint64_t cnt = 9, len = 1, start = 1;
      while(n > cnt * len){
        n -= cnt * len;
        cnt *= 10;
        len++;
        start *= 10;
      }
      start += (n - 1) / len;
      string target = to_string(start);
      return target[(n-1) % len] - '0' ;
    }
};