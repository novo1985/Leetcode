#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    //S[i] = max(S[i-2], S[i-3]) + A[i], which means when choose A[i], the maximum number of S[i]
    int len = nums.size();
    if(len == 0){ return 0;}
    if(len == 1){ return nums[0];} // only one element: nums[0]
    if(len == 2){ return max(nums[0], nums[1]);} // only two elements, pick the bigger one
    vector<int> Sum(len, 0); // create a vector to store S[i]
    Sum[0] = nums[0];
    Sum[1] = max(nums[0],nums[1]);
    //Sum[2] =
    for(int i = 2; i < len; ++len){
      Sum[i] = max(Sum[i-2] + nums[i], Sum[i-1]);
    }
    return Sum[len-1];
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}