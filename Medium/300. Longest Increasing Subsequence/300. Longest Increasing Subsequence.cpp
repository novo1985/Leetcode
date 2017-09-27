/* Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there
may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.*/

//solution1: o(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      //base case: empty
      if(nums.empty()) { return 0;}

      int n = nums.size();
      /* dp[i]: LIS ending with nums[i]
       * dp[i] = max(dp[i], dp[j] + 1), for all index 0 =< j < i && nums[j] < nums[i] */
      int maxlen = 1;
      vector<int> dp(n, 1);
      for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
          if(nums[j] < nums[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
        }
        maxlen = max(maxlen, dp[i]);
      }

      return maxlen;
    }
};

//solution2: o(nlgn)
/* using array int[] len, its index is LIS length
 * len[0] = nums[0]; 长度为1的lis，暂时为nums[0];
 * len[1] = {empty}; 长度为2的lis，
 * len[2] = {empty}; 长度为3的lis，
 *    ...     ...       ...
 * len[n-1] = {empty}; 长度为n的lis，
 * BUT!!! array len only store the tail element
 * for loop: i = 1 to n-1 //binary search
 * update value for each length list ****/

class Solution{
public:
    int lengthOfLIS(vector<int>& nums) {
      //base case: empty array
      if(nums.empty()) {return 0;}

      int res = 0;//initialized len = 1
      vector<int> len(nums.size(), 0);//vector only store tail element for each list == index+1
      len[res] = nums[0];//list with length = 1, the current tail element is nums[0];
      for(int i = 1; i < nums.size(); i++) {
        /* supposed that lists of len = 1 to len = res + 1 , tails are sorted, check boundary */
        if(nums[i] < len[0]) { len[0] = nums[i]; }
        if(nums[i] > len[res]) { len[++res] = nums[i]; }
        //binary search (1, res+1)
        else {
          int left = 0, right = res;
          while(left < right) {
            int mid = left + (right - left)/2;
            if(len[mid] < nums[i]) {
              left = mid + 1;
            }else{
              right = mid;
            }
          }
          len[right] = nums[i];
        }
      }
      return res+1;
    }
};










