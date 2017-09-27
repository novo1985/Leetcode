/* Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4] */

/* it looks like Longest increasing subsequence, integer replaced by pair
 * Dp problems: dp[i] denote as the length of longestchain ending with pair[i], including pair[i]
 * Base case: dp[0] = 1;*********/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      if(pairs.empty() || pairs[0].empty()) return 0;

      sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
      });
      //define dp status
      int n = pairs.size();
      vector<int> dp(n, 1);//dp[i] means the length of LIC ending with pairs[i]
      dp[0] = 1;
      //transition equation: dp[i] = 1; if there is no k, such that pairs[k][1] < pairs[i][0], 0<=k<i
      //                           = 1 + max{dp[k]}
      for(int i = 1; i < n; i++) {
        //dp[i] at least equals to 1
        int temp = 1;
        int MAXI = 0;
        for(int k = 0; k < i; k++) {
          if(pairs[k][1] < pairs[i][0]) {//which is a splitter candidate
            MAXI = max(MAXI, dp[k]);
          }
        }
        dp[i] = temp + MAXI;
      }
      //be careful dp[n-1] might not be the biggest value! it also depends on the "start" [start, finish]
      int res = INT_MIN;
      for(const auto&a : dp){
        if(a > res) { res = a; }
      }
      return res;
    }
};

//greedy
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        stack<vector<int>> st;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto pair : pairs) {
            if (st.empty()) st.push(pair);
            else {
                auto t = st.top();
                if (pair[0] > t[1]) st.push(pair);
            }
        }
        return st.size();
    }
};


