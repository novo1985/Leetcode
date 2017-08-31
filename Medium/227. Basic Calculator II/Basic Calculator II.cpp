#include <bits/stdc++.h>
using namespace std;

/* Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces' '.
 The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5     *******************/


//solution1: use stack
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> nums;
        int d = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++){
          if(isdigit(s[i]) != 0){
            d = 10*d + (s[i] - '0');
          }
          if((isdigit(s[i]) == 0 && s[i] != ' ') || i == s.size() - 1){
            if(sign == '+') { nums.push(d);} // sign was initailized as '+'
            if(sign == '-') { nums.push(-d);}
            if(sign == '*' || sign == '/'){
              int temp = (sign == '*')? nums.top() * d : nums.top() / d;
              nums.pop();
              nums.push(temp);
            }
            sign = s[i];
            d = 0;
          }
        }

        //add all element in the stack
        while(!nums.empty()){
          res += nums.top();
          nums.pop();
        }

        return res;
    }
};








