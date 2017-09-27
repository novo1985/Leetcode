/* Given an unsorted array of integers, find the number of longest increasing subsequence.*/

/* len[i]: denote as the length of LIS ending with nums[i]
 * count[i]: denote as the number of LIS ending with nums[i]
 * maxlen = max(maxlen, len[i])
 * count_of_maxlen = sum(count[i]), which len[i] = maxlen;
 * How to get len[i] & count[i]?
 * 1)len[i] = 1,               if there is no k such that nums[k] < nums[i]
 *          = 1 + max{len[k]}, where k ranges[0, .. i-1] & nums[k] < nums[i]
 * 2)count[i] = 1,  if there is no k such that nums[k] < nums[i]
 *            = sum of count[k];    if nums[k] < nums[i] & len[k] + 1 = len[i] *****/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      if(nums.empty()) return 0;

      int n = nums.size();
      vector<int> len(n, 1);
      vector<int> count(n, 1);
      int maxlen = 1;
      for(int i = 1; i < n; i++) {
        for(int k = 0; k < i; k++) {
          if(nums[k] < nums[i]) {
              //len[i] = max(len[i], len[k] + 1);
              if(len[k] + 1 > len[i]) {
                  len[i] = len[k] + 1;
                  count[i] = count[k];

              } else if(len[k] + 1 == len[i]) {
                  count[i] += count[k];
              }
          }
        }
        maxlen = max(maxlen, len[i]);
      }
        cout << "the length of LIS is " << maxlen << endl;

      int res = 0;
      for(int i = 0; i < n; i++) {
        if(len[i] == maxlen) {
          res += count[i];
        }
      }
      return res;
    }
};





