#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].   ******/

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
}
/*inorder: 1,(recursively call)left_subtree;
 *         2, root;
 *         3,(recursively call)right_subtree;  */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      if(!root){ return res; }
      dfs(root, res);
      return res;

    }
    void dfs(TreeNode* root, vector<int>& res){
      if(!root) { return res; }
        dfs(root->left, res);
        res.push_back(root->val, res);
        dfs(root->right);
    }
};

//Iterative solution using stack --- O(n) time and O(n) space;
//面试中应该不会只考递归这么简单。所以迭代解法才是真正的重点。

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<TreeNode*> s;
      TreeNode* cur = root;
      while(cur || !s.empty()){
        if(cur){
          s.push(cur);
          cur = cur->left;
        }
        else{
          cur = s.top();
          s.pop();
          res.push_back(cur->val);
          cur = cur->right;
        }
      }
      return res;
    }
};




