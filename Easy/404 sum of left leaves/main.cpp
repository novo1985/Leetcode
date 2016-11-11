#include <iostream>

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};
class solution{
  // no defined constructor
  int sumOfLeftLeaves(TreeNode* root){
    int sum = 0;
    if(!root){ return 0;}
    else if(root->left && !root->left->left && !root->left->right){
      sum += root->left->val;
    }
      int lc_sum = sumOfLeftLeaves(root->left);
      int rc_sum = sumOfLeftLeaves(root->right);
      sum += lc_sum + rc_sum;
      return sum;
  }
};
int main() {
  solution test;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}