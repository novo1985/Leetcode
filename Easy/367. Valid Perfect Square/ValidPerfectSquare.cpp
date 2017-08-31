#include <iostream>
using namespace std;

/* Given a positive integer num, write a function which returns True if num
 * is a perfect square else False.
 * Note: Do not use any built-in library function such as sqrt.  *************/

class Solution {
public:
    bool isPerfectSquare(int num) {
      if(num == 1) { return true; }
      uint64_t start = 0, end = num;
      uint64_t mid = 0;
      while ( start <= end){
        mid = start + (end - start)/2;
        if(mid * mid == num) { return true; }
        else if(mid * mid > num){
          end = mid-1;
        }
        else{
          start = mid+1;
        }
      }
      return false;
    }
};