#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    // divide and conquer: the max_subarray will include the pointer or not include the pointer (as the pointer increment)
    if(nums.empty()){return 0;}
    int low_excl = 0;
    int high_excl = 0;
    int low_incl = 0;
    int high_incl = 0;
    int sum_excl = nums[0];
    int sum_incl = nums[0];
    for(int i = 1; i < nums.size(); i++){
      // step 1: including the edge and update the values
      if(sum_incl < 0){
        low_incl = i;
        high_incl = i;
        sum_incl = nums[i];
      }else{
        high_incl = i;
        sum_incl += nums[i];
      }

      // step 2: compare the sum-ex and sum-in and update the sum-ex
      if(sum_incl > sum_excl){ // compare with the older, excluding the new index
        low_excl = low_incl;
        high_excl = high_incl;
        sum_excl = sum_incl;
      }
    }
    cout << "low index is " << low_excl << endl;
    cout << "high index is " << high_excl <<endl;
    return sum_excl;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}