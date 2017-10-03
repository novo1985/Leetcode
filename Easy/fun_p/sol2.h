//
// Created by Lei Gao on 9/28/17.
//

#ifndef FUN_P_SOL2_H
#define FUN_P_SOL2_H
#include <vector>
#include <stack>
using namespace std;

class Solution2{
public:
  void changearray(vector<int>& nums){
    stack<int> st;
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
      while(!st.empty() && nums[st.top()] > nums[i]) {
        sum += nums[st.top()] - nums[i];
        st.pop();
      }
      st.push(i);
    }
    while(!st.empty()) {
      sum += nums[st.top()];
      cout << st.top() << endl;
      st.pop();
    }
    cout << "sum is " << sum << endl;
  }
};
#endif //FUN_P_SOL2_H
