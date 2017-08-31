#include <bits/stdc++.h>
using namespace std;

/* Given an integer n, generate all structurally unique BST's (binary search trees) that store
 * values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3           ***********************************/

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
      if(n == 0) { return {}; }
      return dfs(1, n);
    }
    vector<TreeNode*> dfs(int start, int end){
      vector<TreeNode*> res;
      if(start > end) { res.push_back(nullptr); return res;}
      else{
        for(int i = start; i <= end; i++){
          vector<TreeNode*> lefttree = dfs(start, i-1);
          vector<TreeNode*> righttree = dfs(i+1, end);
          for(int j = 0; j < lefttree.size(); j++){
            for(int k = 0; k < righttree.size(); k++){
              TreeNode *root = new TreeNode(i);
              root->left = lefttree[j];
              root->right = righttree[k];
              res.push_back(root);
            }
          }
        }
      }
      return res;
    }
};























