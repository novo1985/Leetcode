#include <bits/stdc++.h>
using namespace std;

/* The thief has found himself a new place for his thievery again. There is only one entrance to
 * this area, called the "root." Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree".
 * It will automatically contact the police if two directly-linked houses were broken into on the
 * same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.    **********/


/*solution1: dp(root) = max[(root->val + !root->left->val + !root->right->val),
 *                                        (root->left->val + root->right->value)]
 * Time Limit Exceeded *******/
class Solution {
public:
    int rob(TreeNode* root) {
      if(!root) { return 0;}
      int val = 0;
      if(root->left){
        val += rob(root->left->left) + rob(root->left->right);
      }
      if(root->right){
        val += rob(root->right->left) + rob(root->right->right);
      }

      return max(val + root->val, rob(root->left) + rob(root->right));
    }
};

//solution2: recursion and hash table
class Solution {
public:
    int rob(TreeNode* root) {
      unordered_map<TreeNode*, int> m;
      return dfs(root, m);
    }
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& m){
      if(!root) { return 0; }
      if(m.count(root)) { return m[root];} //if input TreeNode* already stored in map, return
      int val = 0;
      if(root->left){
        val += dfs(root->left->left, m) + dfs(root->left->right, m);
      }
      if(root->right){
        val += dfs(root->right->left, m) + dfs(root->right->right, m);
      }
      val = max(val + root->val, dfs(root->left, m) + dfs(root->right, m));
      m[root] = val;
      return val;
    }
};

//solution3: [0] not include current root; [1] include current root;
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode *root) {
        if (!root) return vector<int>(2, 0);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> res(2, 0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
        return res;
    }
};







