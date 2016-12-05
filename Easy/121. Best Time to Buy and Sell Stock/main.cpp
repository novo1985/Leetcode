#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    /**
        // First try: O(n^2), which causes the time limited problem
        int res = 0;
        if(prices.size() < 2){return 0;}
        for(int i = 0; i < prices.size() - 1; i++){
            for(int j = i + 1; j < prices.size(); j++) {
                res = max((prices[j] - prices[i]), res);
            }
        }
        return res > 0 ? res : 0;
    */

    //Method 2: try to find the O(n) algorithm.
    if(prices.empty()){ return 0;}

    int res = 0;
    int temp_profit = 0;
    int lowest_price = prices[0];

    for(int i = 1; i < prices.size(); i++){
      temp_profit = prices[i] - lowest_price;
      // update the lowest price
      if(temp_profit < 0){
        lowest_price = prices[i];
      }
      res = max(res, temp_profit);
    }
    return res;
  }
};

int main() {
  Solution test;
  vector<int> v = {7,1,5,3,6,4,100,1,987,24,1048};
  vector<int> v2 = {1};
  cout << "the max profit is " << test.maxProfit(v2) << endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}