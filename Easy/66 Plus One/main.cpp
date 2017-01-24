#include <iostream>
#include <vector>
using namespace std;

/***Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
 479 ===> 4->7->9 ==> vector {4,7,9}
***/

class Solution{
public:
  vector<int> plusOne(vector<int>& digits){  //input of integer is already presented as vector
    // we need carry
    reverse(digits.begin(),digits.end()); // return value of "reverse" is none, copy is not good, it takes memory space!
    int carry = 1;
    int n = digits.size();
    for(int i = 0; i < n; ++i){
      int temp = digits[i] + carry;
      digits[i] = temp % 10;
      if(temp < 10) {carry = 0;}
    }
    if(digits[n-1]==0){digits.push_back(1);}
    reverse(digits.begin(),digits.end());
    return digits;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}