//
// Created by Lei Gao on 9/28/17.
//

#ifndef FUN_P_SOL_H
#define FUN_P_SOL_H

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int getScope(string& s) {
    //corner case: empty s
    if(s.empty()) return 0;
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 1));
    for(int len = 2; len <= n; len++) {
      for(int i = 0; i <= n - len; i++) {
        int j = len + i - 1;
        if (s[i] == s[j] && len == 2) { dp[i][j] = 2; }
        else if(s[i] == s[j]) {
          dp[i][j] = 2 + dp[i+1][j-1];
        }
        else {
          dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
      }
    }

    int maxproduct = 1;
    for(int i = 1; i <= n-2; i++) {
      maxproduct = max(maxproduct, dp[0][i] * dp[i+1][n-1]);
    }

    return maxproduct;
  }
};

#endif //FUN_P_SOL_H
