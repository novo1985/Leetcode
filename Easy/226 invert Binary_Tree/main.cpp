#include <iostream>

/**
 * Definition for a binary tree node.*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/** invert binary tree */
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if(!root){
      return NULL;
    }

    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}