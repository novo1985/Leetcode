#include <iostream>
using namespace std;

/* We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 *
 * You call a pre-defined API guess(int num) which returns
 * 3 possible results (-1[low], 1[high], or 0[correct]): ***********************/

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
      // n means array{1,2,3,...,n}, program should return the picked number
      if(guess(n) == 0) { return n;}
      uint64_t start = 1, end = n;
      uint64_t mid = 0;
      while(start <= end){
        mid = start + (end - start)/2;
        if(guess(mid) == 0) { return mid;}
        else if(guess(mid) == 1){
          start = mid + 1;
        }else{
          end = mid - 1;
        }
      }
      return start;
    }
};