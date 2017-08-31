#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the
 * given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]                                         *******************************************/

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

/*
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;

        sum -= root->val;
        if(!root->left && !root->right)
            return sum==0 ? true : false;

        if(root->left && hasPathSum(root->left,sum)) return true;
        if(root->right && hasPathSum(root->right,sum)) return true;
        return false;
    }
};
*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> res;
      vector<int> sol;
      dfs(root, res, sol, sum);
      return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& sol, int sum){
      if(!root) { return; }
      sol.push_back(root->val);
      if(!root->left && !root->right && root->val == sum){
        res.push_back(sol);
      }
      else{
        if(root->left){ dfs(root->left, res, sol, sum - root->val);}
        if(root->right) { dfs(root->right, res, sol, sum - root->val);}
      }
      sol.pop_back();
    }
};









