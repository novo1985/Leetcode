#include <bits/stdc++.h>
using namespace std;

/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
 * input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]"
are not. ************/

/* solution: using stack, iterate from index = 0 to index = size-1, if '(', '{', '[', push it into
 * stack, if ) ] }, we pop char from stack, if they match wrong, return false*/
class Solution{
public:
  bool isValid(string s){
    if(s.empty()) { return true; }
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '(' || s[i] == '{' || s[i] == '['){
        st.push(s[i]);
      }else{
        if(st.empty()) { return false;}
        char c = st.top();
        st.pop();
        if((s[i] == ')' && c != '(') || (s[i] == ']') && c != '[' || (s[i] == '}') && c != '{'){
          return false;
        }
      }
    }
    return st.empty()? true : false; // return st.empty();
  }
};

