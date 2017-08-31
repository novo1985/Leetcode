#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3]. ************/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//solution1: recursive
class Solution{
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(res, root);
    return res;
  }

  void dfs(vector<int>& res, TreeNode* root){
    if(!root) { return; }
    res.push_back(root->val);
    dfs(res, root->left);
    dfs(res, root->right);
  }
};

//solution2: iteration, if traverse tree by iteration, we need extra space stack or queue.
class Solution{
public:
  vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> s;
    if(!root) { return res; }
    s.push(root);
    while(!s.empty()){
      TreeNode* cur = s.top();
      s.pop();
      res.push_back(cur->val);
      if(cur->right) { s.push(cur->right);}
      if(cur->left) { s.push(cur->left);}
    }
    return res;
  }
};


























