#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6  ********************/

/* preorder:
 * root
 * recursively call left_subtree
 * recursively call right_subtree**/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursive1
class Solution{
public:
    void flatten(TreeNode* root) {
      if(!root) { return; }
      if(root->left){ flatten(root->left); }
      if(root->right){ flatten(root->right); }
      TreeNode* temp = root->right;
      root->right = root->left;
      root->left = nullptr;
      while(root->right){ root = root->right; }
      root->right = temp;
    }
};

//iteration
/*   1
    / \
   2   5
  / \   \
 3   4   6

   1
    \
     2
    / \
   3   4
        \
         5
          \
           6  */
class Solution{
public:
    void flatten(TreeNode* root) {
      TreeNode *cur = root;
      while(cur){
        if(cur->left){
          TreeNode *tail = cur->left;
          while(tail->right) { tail = tail->right; }// find the node which connect with root->right
          tail->right = cur->right;
          cur->right = cur->left;
          cur->left = nullptr;
        }
        cur = cur->right;
      }
    }
};











