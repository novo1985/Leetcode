//all houses at this place are arranged in a circle

/* solution: House Robber I的升级版. 因为第一个element 和最后一个element不能同时出现.
 则分两次call House Robber I. case 1: 不包括最后一个element. case 2: 不包括第一个element.*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) { return 0; }
        if(nums.size() == 1) { return nums[0]; }
        int n = nums.size();
        return max(robber(nums, 0, n-1), robber(nums, 1, n));//max of two cases [0, n-2] and [1, n-1]
    }

    int robber(vector<int>& nums, int start, int end) {
        if(end - start == 1) { return max(nums[start], nums[end]); }
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start+1], nums[start]);

        for(int i = start+2; i < end; i++) {
          dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[end-1];
    }
};





