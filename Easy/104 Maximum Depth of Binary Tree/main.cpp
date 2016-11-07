#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/** Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/** Given a binary tree, find its maximum depth */
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if(root == NULL){return 0;}
    int lmax = maxDepth(root->left);
    int rmax = maxDepth(root->right);
    return max(lmax, rmax)+1;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}