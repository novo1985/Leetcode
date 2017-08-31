#include <bits/stdc++.h>
using namespace std;

/* You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9] ******/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
      vector<int> res;
      if(!root) { return res; }
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int n = q.size();
        int max = INT_MIN;
        for(int i = 0; i < n; i++){
          TreeNode *cur = q.front();
          q.pop();
          if(cur->left){ q.push(cur->left); }
          if(cur->right){ q.push(cur->right); }
          max = max < cur->val ? cur->val : max;
        }
        res.push_back(max);
      }
      return res;
    }
};





