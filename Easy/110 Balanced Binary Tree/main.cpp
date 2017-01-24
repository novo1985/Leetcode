#include <iostream>
#include <cmath>
using namespace std;
/**
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined
 * as a binary tree in which the depth of the two subtrees of
 * every node never differ by more than 1.
 * @return
 */
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
public:
  int cal_Depth(TreeNode* root){
    if(!root){ return 0;}
    int left_depth = cal_Depth(root->left);
    if(left_depth == -1){ return -1;}
    int right_depth = cal_Depth(root->right);
    if(right_depth == -1){ return -1;}
    if(abs(left_depth - right_depth) > 1) { return -1;}
    return max(left_depth,right_depth)+1;
  }
  bool isBalanced(TreeNode* root){
    return cal_Depth(root)==-1? false : true;
  }
  /**
   * int cal_Depth(TreeNode* root){
   *    if(!root){return 0;}
   *    int left_depth = cal_Depth(root->left);
   *    int right_depth = cal_Depth(root->right);
   *    return max(left_depth, right_depth);
   * }
   * bool isBalanced(TreeNode* root){
   *    if(!root){return true;}
   *    if(abs(cal_Depth(root->left) - cal_Depth(root->right)) > 1){return false;}
   *    bool lc = isBalanced(root->left);
   *    bool rc = isBalanced(root->right);
   *    return lc && rc;
   * }
   */
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}