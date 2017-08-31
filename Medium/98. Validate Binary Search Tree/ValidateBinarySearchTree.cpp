#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.

Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.      *********************************************/

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
      return checkBST(root, LONG_MIN, LONG_MAX);
    }
    bool checkBST(TreeNode* root, long min, long max){
      if(!root) { return true; }
      if(min >= root->val || max <= root->val){ return false;}
      return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
    }
};


//inorder traveral
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        for (int i = 0; i < vals.size() - 1; ++i) {
            if (vals[i] >= vals[i + 1]) return false;
        }
        return true;
    }
    void inorder(TreeNode *root, vector<int> &vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};





























