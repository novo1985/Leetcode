#include <bits/stdc++.h>
using namespace std;

/* Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.*/

//solution1:  using  stack<int>, for while stack
class Solution {
public:
    int trap(vector<int>& height) {
      if(height.empty()) { return 0;}
      int res = 0;
      stack<int> s;// store descent indices
      s.push(0);
      for(int i = 1; i < height.size(); i++){
        //ascending point
        if(height[i] > height[s.top()]){
          int base = height[s.top()];
          while(!s.empty() && height[s.top()] <= height[i]){
          // repeat operation if next top of stack is low than new height[i]
            res += (height[s.top()] - base) * (i - s.top() - 1);//heigth diff * width
            base = height[s.top()];
            s.pop();
          }

          //剩下一个低的bar = base，stack为空； 或者，剩下一个低的bar = base，stack 还有一个高的bar
          if(!s.empty()) { res += (height[i] - base) * (i - s.top() -1); }
        }
        s.push(i);
      }
      return res;
    }
};

//solution2: two pointer, 针对每一index 分析！！！每一个index 取决于其 左边最高值和右边最高值！
class Solution {
public:
    int trap(vector<int>& height) {
      if(heigh.size() < 3) { return 0;}
      int n = height.size();
      vector<int> leftheight(n, 0);//store index i : left side most height
      vector<int> rightheight(n, 0);//store index i : right side most height
      int res = 0;
      for(int i = 1; i < n; i++){
        leftheight[i] = max(leftheight[i-1], height[i-1]);
      }
      for(int i = n-2; i>=0; i--){
        rightheight[i] = max(rightheight[i+1], height[i+1]);
        int min = min(leftheight[i], rightheight[i]);
        if(min > height[i]){ res += min - height[i]; }
      }
      return res;

    }
};








