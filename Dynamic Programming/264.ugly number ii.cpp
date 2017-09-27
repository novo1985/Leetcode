class Solution {
public:
    int nthUglyNumber(int n) {
       int i2 = 0, i3 = 0, i5 = 0;
       vector<int> dp(n+1, 0);

       dp[1] = 1;
       for(int i = 2; i <= n; i++) {
           int u2 = dp[i2+1] * 2, u3 = dp[i3+1] * 3, u5 = dp[i5+1] * 5;
           int min_u = min(u2, min(u3, u5));
           if(min_u == u2) i2++;
           if(min_u == u3) i3++;
           if(min_u == u5) i5++;
           dp[i] = min_u;
       }

       return dp[n];
    }
};