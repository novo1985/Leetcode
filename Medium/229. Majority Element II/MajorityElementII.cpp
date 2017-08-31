#include <bits/stdc++.h>
using namespace std;

/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 * The algorithm should run in linear time and in O(1) space.              ****************/

//time = o(n) & space = o(1)
//no sorting; no hash table!!!
/* 这么苛刻的限制条件只有一种方法能解了，那就是摩尔投票法 Moore Voting
 * 任意一个数组出现次数大于n/3的众数最多有两个.
 * 我们使用投票法的核心是找出两个候选众数进行投票，需要两遍遍历，
 * 第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可 *********************/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int len = nums.size();
      vector<int> res; // at least two elements
      int m = 0, n = 0, cm = 0, cn = 0; // m n is the candidates cm cn is frequency
      for(auto &a : nums){
        if(a == m) { cm++; }
        else if(a == n) { cn++; }
        else if(cm == 0) { m = a, cm = 1; }
        else if(cn == 0) { n = a, cn = 1; }
        else cm--, cn--;
      }
      //check candidate m and n
      cm = 0, cn = 0;
      for(auto &a : nums){
        if(a == m) { cm++; }
        else if( a == n) { cn++; }
      }
      if(cm > len/3) { res.push_back(m); }
      if(cn > len/3) { res.push_back(n); }
      return res;
    }
};



























