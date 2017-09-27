/* Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and
 * others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?*/


/* First iteration: swap, put the number to its right position
 * Second iteration: check, find those nums[i] != i+1 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      //corner case: empty array
      vector<int> res;
      if(nums.empty()) { return res; }
      //first iteration:
      for(int i = 0; i < nums.size(); i++) {
        while(nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
          swap(nums[i], nums[nums[i]-1]);
        }
      }

      //second itertion:
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i+1) {
          res.push_back(nums[i]);
        }
      }

      return res;
    }
};










