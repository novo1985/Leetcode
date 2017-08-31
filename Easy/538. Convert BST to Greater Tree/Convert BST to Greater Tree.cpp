class Solution{
public:
  TreeNode* getGreaterTree(TreeNode* root){
    //int sum = 0;
    helper(root, 0);
    return root;
  }
  /* helper function: calculate the sum of right_subtree */
  void helper(TreeNode* node, int& sum){
    if(!node) { return; }
    helper(node->right, sum);
    node->val += sum;
    sum = node->val;
    helper(node->left, sum);
  }
};