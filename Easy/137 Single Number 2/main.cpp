#include <iostream>
#include <vector>
using namespace std;

//Given an array of integers, every element appears three times except for one. Find that single one.

class Single_number_2{
public:
  Single_number_2(vector<int>& v):nums(v){}

  //O(n), just a linear runtime
  int single_number(){
    vector<int> bit(32,0);
    int k = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i){
      for (int j = 31; j >= 0; --j){
        bit[j] = nums[i]>>j;
      }
    }
  }


public:
  vector<int> nums;
};





int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}