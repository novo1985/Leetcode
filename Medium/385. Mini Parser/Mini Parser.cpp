#include <bits/stdc++.h>
using namespace std;

/* Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.  ***************************/

//solution1: recursion: start and level
class Solution {
public:
    NestedInteger deserialize(string s) {
      if(s.empty()) { return NestedInteger(); }// NestedInteger 构造函数
      if(s[0] != '[') { return NestedInteger(stoi(s)); } // 说明s 就是一个孤零零的整数
      if(s.size() <= 2) { return NestedInteger(); } // []空的
      NestedInteger res;
      int start = 1, count = 0; // s[0] == '['
      /* count 记录层数； 如果遇到'['，计数器count自增1，若遇到']'，计数器count自减1. count = 0 表示同一深度
       * start 记录当前某一层的实际位置； ********/
      for(int i = 1; i < s.size(); i++){
        if(count == 0 && (s[i] == ',' || i == s.size()-1)){
          res.add(deserialize(s.substr(start, i - start)));
          start = i+1;
        }
        else if(s[i] == '[') { count++; }
        else if(s[i] == ']') { count--; }
      }
      return res;
    }
};

//solution2: 迭代的方法来做，这样就需要使用栈来辅助
class Solution{
public:
    NestedInteger deserialize(string s){
      if(s.empty()) { return NestedInteger(); }
      if(s[0] != '[') { return NestedInteger(stoi(s)); }
      if(s.size() <= 2) { return NestedInteger(); }
      stack<NestedInteger> s;
      int start = 1;
      for(int i = 0; i < s.size(); i++){
        if(s[i] == '['){
          s.push_back(NestedInteger()); // 加一个空的NestedInteger
          start = i + 1;
        }
        else if(s[i] == ',' || s[i] == ']'){
          if(i > start){
            s.top().add(NestedInteger(stoi(s.substr(start, i - start))));
          }
          start = i + 1;
          if(s[i] == ']'){
            if(s.size() > 1){
              NestedInteger t = s.top(); s.pop();
              st.top().add(t);
            }
          }
        }
      }
      return st.top();
    }
};









/*
class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };

*/






