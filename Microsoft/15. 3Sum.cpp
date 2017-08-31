//follow the logical of two sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumGeneral(nums, 0);
    }
    vector<vector<int>> threeSumGeneral(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        if(nums.empty() || nums.size() < 3) { return res; }
        //sort the array first, then we can use two pointers methods
        sort(nums.begin(), nums.end());
        //possible searching start point is: i = 0 to n-3;
        int n = nums.size();
        for(int i = 0; i <= n-3; i++) {
          if(i > 0 && nums[i] == nums[i-1]) { continue; }//avoid dupicate results
          int j = i+1, k = n-1;
          while(j < k) {
            if(nums[j] + nums[k] == target - nums[i]) {
              sol.push_back(nums[i]);
              sol.push_back(nums[j]);
              sol.push_back(nums[k]);
              res.push_back(sol);
              sol.clear();
              j++;
              k--;
              while(nums[j] == nums[j-1]) { j++; }
              while(nums[k] == nums[k+1]) { k--; }
            }

            else if(nums[j] + nums[k] > target - nums[i]) {
              k--;
            }
            else {
              j++;
            }
          }
        }
        return res;
    }
};