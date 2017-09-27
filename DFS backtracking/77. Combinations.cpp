/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.*/

//array [ 1, .. ,n]! backtracking!
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> res;
      vector<int> sol;
      if(k > n) { return res; }
      dfs(1, k, n, sol, res);
      return res;
    }

    void dfs(int start, int k, int n, vector<int>& sol, vector<vector<int>>& res) {
      //backtracking return condtion: sol.size() == k
      if(sol.size() == k) {
        res.push_back(sol);
        return;
      }

      //stop condtion, can not add any number
      if(start > n) { return; }

      //DFS recursion:
      for(int i = start; i <= n; i++) {
        sol.push_back(i);
        dfs(i+1, k, n, sol, res);
        sol.pop_back();
      }
    }
};

























