#include <iostream>
#include <cmath>

class Solution {
public:
  int climbStairs(int n) {
   /**
    * there are total n ladders in the stair, each step you
    * can climb 1 or 2 steps, how many ways you get to the top?
    int num_one = 0;
    int num_two = 0;
    int res = 0;

      // integer i records how many '2', and also means how many cases
    for(int i = 0; i < n/2; i++){
      num_one = n - 2*i;
      num_two = i;
      // suppose there are 'num_one + 1' buckets, we need figout how many different patters
      //we can put 'num_two' of '2' into these buckets?
      //it seems difficult~
      res += pow(num_one + 1, num_two);
      std::cout << "current result is " << res << std::endl;
    }
    return res;
    */

    //using dynamic programing, if way(i-1) record the number ways of step i-1
    //way(i-2) records the number ways of step i-2
    //then the number of pathways to get the step i way(i) = way(i-1) + way(i-2)
    //if(n==0){ return n=0;}
    //if(n==1){ return n=1;}
    //if(n==2){ return n=2;}
    //if(n==3){return 1+2 = 3;}
    //if(n==4){return 2+3 = 5;}
    //so it is a fibonacci number
    int f1 = 1;
    int f2 = 2;
    //new f2 = f1 + f2
    //new f1 = f2 - f1
    for(int i = 3; i <= n; i++){
      f2 = f1 + f2;
      f1 = f2 - f1;
    }
    return f2;


  }
};
int main() {
  Solution test;
  int n = 5;
  std::cout << "the total number of ways to climb the stair is " << test.climbStairs(n) << std::endl;
  std::cout << "Done, thanks!" << std::endl;
  return 0;
}