#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(!root){
      return false;
    }
    if(root->val == sum && !root->left && !root->right){
      return true;
    }
    sum -= root->val;
    bool lc = hasPathSum(root->left, sum);
    bool rc = hasPathSum(root->right, sum);
    if(lc || rc){
      return true;
    }

    return false;

  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}