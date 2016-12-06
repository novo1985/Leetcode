#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
/** Find the number of paths that sum to a given value.
 *  The path does not need to start or end at the root or a leaf, but it must go downwards
 */
class Solution {

public:
  int pathSum(TreeNode *root, int sum) {
    if(!root){ return 0;}
    return calc(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }

  int calc(TreeNode *node, int cur_sum, int sum) {
    if (!node) { return 0; }
    int res = 0;
    cur_sum += node->val;
    if(cur_sum == sum) {res++;}
    return res + calc(node->left, cur_sum, sum) + calc(node->right, cur_sum, sum);
  }

};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}