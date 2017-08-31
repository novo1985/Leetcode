#include <bits/stdc++.h>
using namespace std;

/* Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you
like (ie, buy one and sell one share of the stock multiple times). However, you may not engage
in multiple transactions at the same time (ie, you must sell the stock before you buy again). ****/

/* solution1: O(n) maxprofit, lowestPrice, profit */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.empty()){ return 0;}
      int n = prices.size();
      int maxprofit = 0, lowestPrice = prices[0];
      for(int i = 1; i < n; i++){
        int profit = prices[i] - lowestPrice;
        if(profit < 0){
          lowestPrice = prices[i];
        }
        else{
          maxprofit += profit;
          lowestPrice = prices[i];
        }
      }
      return maxprofit;
    }
};

/* solution2: O(n) DP
 * Define dp[i] = maxprofit ending with prices[i]: [0, ..., i]
 * dp[i+1] = max(dp[i], dp[i] + prices[i+1] - prices[i]) ********/
class Solution{
public:
  int maxProfit(vector<int>& prices){
    if(prices.empty()) { return 0; }
    int n = prices.size();
    vector<int> dp(n, 0);
    //int lowestPrice = prices[0];
    for(int i = 1; i < n; i++){
      dp[i] = max(dp[i-1], dp[i-1]+prices[i]-prices[i-1]);
    }
    return dp[n-1];
  }
};













