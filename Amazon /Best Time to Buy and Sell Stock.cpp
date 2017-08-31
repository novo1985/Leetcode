#include <bits/stdc++.h>
using namespace std;

/* Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one
share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0. *****************************/

/* soluton1: 因为只能后面的元素减去前面的元素， 设定一个lowest price，如果后面的值更小， 就更新！
 *           if nums[i] < lowest price; nums[i+1] - nums[i] > nums[i+1] - loweset price
 *           当有profit的时候， 不用把所有的可能的利润存下来， 只需要stroe最大值：
 *           maxprofit = max(profit, maxprofit)*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // O(n) time complexity
      if(prices.empty()) return 0;
      int maxprofit = 0;
      int lowesetP = prices[0];
      for(int i = 1; i < prices.size(); i++){
        int profit = prices[i] - lowesetP;
        if(profit < 0){
          lowesetP = prices[i];
        }else{
          maxprofit = max(profit, maxprofit);
        }
      }
      return maxprofit;
    }
};
/* solution2: DP算法2：设dp[i]是[0,1,2...i]区间的最大利润，则该问题的一维动态规划方程如下

dp[i+1] = max{dp[i], prices[i+1] - minprices}  ,minprices是区间[0,1,2...,i]内的最低价格

我们要求解的最大利润 = max{dp[0], dp[1], dp[2], ..., dp[n-1]}*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // O(n) time complexity
      if(prices.empty()) { return 0; }
      int n = prices.size();
      vector<int> dp(n, 0);
      dp[0] = 0;
      int maxprofit = dp[0];
      int minprice = prices[0];
      for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1], prices[i] - minprice);
        maxprofit = max(maxprofit, dp[i]);
        minprice = min(minprice, prices[i]);
      }
      return maxprofit;
    }
};















