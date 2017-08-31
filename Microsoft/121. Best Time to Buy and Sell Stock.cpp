//solution1: Dp
/* Let denote dp[i] as maxprofit until i day
 * dp[i] = max(dp[i-1], prices[i] - lowestprice)
 * time: o(n), space o(n) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(price.empty()) { return 0; }
      vector<int> dp(prices.size(), 0);//dp[0] = 0;
      int lowestprice = prices[0];
      int maxprofit = 0;
      for(int i = 1; i < prices.size(); i++) {
        dp[i] = max(dp[i-1], prices[i] - lowestprice);
        maxprofit = max(maxprofit, dp[i]);
        lowestprice = min(lowestprice, prices[i]);
      }
      return maxprofit;
    }
};

//space o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      //does not store each step value
      if(prices.empty()) { return 0; }
      int lowestprice = INT_MAX;
      int maxprofit = 0;
      for(int i = 0; i < prices.size(); i++) {
        if(prices[i] - lowestprice > maxprofit){
          maxprofit = prices[i] - lowestprice;
        }
        if(prices[i] < lowestprice) {
          lowestprice = prices[i];
        }
      }
      return maxprofit;
    }
};



