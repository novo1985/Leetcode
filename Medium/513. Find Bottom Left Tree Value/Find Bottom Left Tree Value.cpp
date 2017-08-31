#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
-----------------------
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
-----------------------****************/

//solution1: iteration, queue
class Solution{
public:
  int findBottomLeftValue(TreeNode* root){
    vector<vector<int>> res;
    if(!root) { return NULL; }
    queue<TreeNode*> q; // store left->right
    vector<int> sol;
    q.push(root);
    while(!q.empty()){
      int n = q.size();
      for(int i = 0; i < n; i++){
        TreeNode* cur = q.front();
        q.pop();
        sol.push_back(cur->val);
        if(cur->left) { q.push(cur->left);}
        if(cur->right){ q.push(cur->right);}
      }
      res.push_back(sol);
      sol.clear();
    }
    int n = res.size();
    return res[n-1][0];
  }
};

//SOLUTION2:
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front(); q.pop();
                if (i == 0) res = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};








