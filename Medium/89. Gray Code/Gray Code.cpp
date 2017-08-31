/* 例举grey code序列，并找规律 :
n = 0: 0
n = 1: 0, 1
n = 2: 00, 01, 11, 10  (0, 1, 3, 2)
n = 3: 000, 001, 011, 010, 110, 111, 101, 100 (0, 1, 3, 2, 6, 7, 5, 4)
以n = 3为例，grey code中前4个包括了n = 2的所有gray code。后4个则是前4个逆序后加上2^2。

推广：n = i的grey code的前一半包括了n = i-1的所有grey code，而后一半则为前一半逆序后家上2^(i-1)。*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> greySeq;
        if(n<0) return greySeq;
        greySeq.push_back(0);
        int inc = 1;
        for(int i=1; i<=n; i++) {
            for(int j=greySeq.size()-1; j>=0; j--){
                greySeq.push_back(greySeq[j]+inc);
            }
            inc <<= 1;
        }
        return greySeq;
    }
};

//solution2: dp
class Solution{
public:
    vector<int> grayCode(int n){
      vector<vector<int>> dp;
      dp[0] = {0};
      int add = 1;
      for(int i = 1; i <= n; i++){
        for(int j = dp[i-1].size()-1; j >= 0; j--){
          dp[i] = dp[i-1].push_back(dp[i-1][j] + add);
        }
        add = 1 << add;
      }
      return dp[n];
    }
};





















