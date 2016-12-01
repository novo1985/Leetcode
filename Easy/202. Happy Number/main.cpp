#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
//positive number replace by the sum of the squares of all its digits. repeat until it becomes to "1"
/** how to cease the endless loop?
 *  For happy number, loop will be terminate when number update to 1
 *  But unhappy number, the loop will be endless, how to judge this ?
 * */
class Solution {
public:
    bool isHappy(int n) {
      if(n == 1){return true;}

      unordered_map<int, int> m;
      m[n]++;
      while(n != 1){
        // First step, we need get the digits of the number, it can be done by using "% 10"
        int temp = 0;
        while(n != 0) {
          temp += (n % 10) * (n % 10);
          n = n/10;
        }
        n = temp;
        m[n]++;
        if(m[n] > 1){break;}
      }
      for(auto iter : m){
        if(iter.second == 2 && iter.first != 1){
          return false;
        }
      }
      return true;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}