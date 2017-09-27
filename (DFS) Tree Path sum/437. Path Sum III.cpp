/* The path does not need to start or end at the root or a leaf, but it must go downwards
 * (traveling only from parent nodes to child nodes).
 * Find the number of paths that sum to a given value.*/

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
      if(!root) { return 0; }
      return calc(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int calc(TreeNode* node, int sum){
      int count = 0;
      if(!node) { return count; }
      if(node->val == sum) { count++; }
      count += calc(node->left, sum - node->val) + calc(node->right, sum - node->val);
      return count;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {

    }
};




