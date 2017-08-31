#include <iostream>
#include <string>
#include <vvector>
using namespace std;

/* Given n pairs of parentheses, write a function to generate all combinations of well-formed
 * parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]               ****************************/

//solution1: recursion ---processed and to be finished part----|-----unprocessed part ---
/* in the unprocessed part (()))) the reminder right has the possibility match with left in the to be
 * finished part, however (((()), the reminder left is unmatched!!!! */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      dfs(n, n, "", res);
      return res;
    }
    void dfs(int left, int right, string out, vector<string>& res){
      if(left > right) { return; }
      if(left == 0 && right == 0){ res.push_back(out); }
      else{
        if(left > 0) { dfs(left-1, right, out+'(', res); }
        if(right > 0) { dfs(left, right-1, out +')', res); }
      }
    }
};

/* solution2: 这种方法的思想是找左括号，每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个(),
 * 就形成了所有的情况，需要注意的是，有时候会出现重复的情况，所以我们用set数据结构，好处是如果遇到重复项，不会加入
 * 到结果中，最后我们再把set转为vector即可，参见代码如下: */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> t;
        if (n == 0) t.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        t.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                t.insert("()" + a);
            }
        }
        return vector<string>(t.begin(), t.end());
    }
};








