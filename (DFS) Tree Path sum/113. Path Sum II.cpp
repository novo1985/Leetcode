/* Given a binary tree and a sum,
 * find all root-to-leaf paths where each path's sum equals the given sum.*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> res;
      vector<int> sol;
      dfs(root, sum, sol, res);
      return res;
    }

    void dfs(TreeNode* node, int sum, vector<int>& sol, vector<vector<int>>& res) {
      //stop condition
      if(!node) { return; }
      //acceptable solution: all start from root to leaf
      sol.push_back(node->val);
      if(!node->left && !node->right && sum == node->val) {
        res.push_back(sol);
        //return;
      }
      dfs(node->left, sum - node->val, sol, res);
      dfs(node->right, sum - node->val, sol, res);
      sol.pop_back();
    }
};









