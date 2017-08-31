//two pointers, and erase function [first end)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.empty()) { return 0; }
      int slow = 0;
      for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[slow]) {
          nums[++slow] = nums[i];
        }
      }
      nums.erase(nums.begin()+slow+1, nums.end());
      return slow+1;
    }
};