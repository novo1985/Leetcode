#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) {

    //check empty
    if(nums.size() == 0){ return 0;}

    // calculate sum of array and check array is equal or not
    int sum = 0;
    bool equal = false;
    int min_step = 0;
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] != nums[i+1]){
        equal = false;
      }
      else {
        equal = true;
      }
      sum += nums[i];
    }

    if(equal == true){
      min_step = 0;
    }

    /** calculate the minMoves:
     * Find maximum element at each step, the left element are increased by 1
     * which equals to all elements add 1 (it does not change the relative size), and then maximum minus 1
     * therefore, skip the first part (all add one), we only find the maxium for each step and then maxium minus1
     * */
    int min_element = nums[0];

    for(int i = 0; i < nums.size(); i++){
      min_element = min(min_element, nums[i]);
    }

    for(int i = 0; i < nums.size(); i++){
      min_step += (nums[i] - min_element);
    }
    cout << "the minimum steps to equalize all element is " << min_step << endl;
    return min_step;
  }
};

int main() {
Solution test;
vector<int> v = {1,2,3,4};
test.minMoves(v);
std::cout << "Hello, World!" << std::endl;
return 0;
}