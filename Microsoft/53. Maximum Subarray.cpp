//Dp problem: dp[i] maxsubarray ending with nums[i]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) { return 0; }
        vector<int> dp (nums.size(), 0);
        dp[0] = nums[0];
        int maxsum = dp[0];
        int start = 0;//begining of maxsubarray
        for(int i = 1; i < nums.size(); i++) {
          dp[i] = max(nums[i], dp[i-1] + nums[i]);
          maxsum = max(dp[i], maxsum);
        }
        return maxsum
    }
};

//no extra space
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
      if(nums.empty()) { return 0; }
      int maxsum = nums[0];
      int maxarray = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        maxarray = max(nums[i], maxarray + nums[i]);
        maxsum = max(maxsum, maxarray);
      }
      return maxsum;
    }
};

//return subarray
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
      if(nums.empty()) { return 0; }
      int start = 0;
      int end = 0;
      int tempmax = nums[0];
      int maxsum = tempmax;
      for(int i = 1; i < nums.size(); i++) {
        start = tempmax > 0? start : i;
        end = nums[i] >= 0 ? i : start;
        tempmax = max(tempmax + nums[i], nums[i]);
        maxsum = max(tempmax, maxsum);
      }
      cout << "[" << start << ", " << end << "]" << endl;
      return maxsum;
    }
};







