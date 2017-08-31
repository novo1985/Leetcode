#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  bool isPalindrome(int x){
    // reverse x to get x', if x == x' return true
    if(x < 0){return false;}
    if(x != 0 && (x % 10 == 0)){ return false;}
    int rev = 0;
    int temp = x;
    while(temp!=0){
      rev = rev*10 + temp % 10;
      temp = temp / 10;
    }
    if(rev == x){return true;}
    return false;
  }
};
int main() {
  Solution test;
  cout << test.isPalindrome(10200) << endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}