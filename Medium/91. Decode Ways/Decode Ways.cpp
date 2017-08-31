#include <bits/stdc++.h>
using namespace std;

/* A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.*/


/* Solution1: dp[i+1] <==?==> dp[i],  i is the length of string。
 * 1）如果是两位数长度，十位数上不能是“0”， 01， 02， 09 无法用A,B,C表示；
 * 2）如果是一位数长度， 不能是“0”；
 * 3）如果是两位数长度， 需要考虑是不是 > 26 **********/
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if(n == 0 || (n > 1 && s[0] == '0')) { return 0; }
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i < n+1; i++){// i is the length of string
      dp[i] = (s[i-1] == '0')? 0 : dp[i-1]; // i = 1, can not be "0"
      if(i>1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))){//len = 2, 十位数上不为0
        dp[i] += dp[i-2];
      }
    }
    return dp[n];
  }
};


/* 加入ret[i]表示到达step i的方法数，由于step i只能从step i-1或step i-1分别爬1和2步到达，所以：

1. ret[i] = ret[i-1] + ret[i-2]
2. 起始条件：ret[1] = 1, ret[2] = 2
3. 事实上由于ret[i]只由前两个结果决定，并不需要储存整个队列。*/
int climbStairs(int n)
    {
        vector<int> res(n+1);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }







