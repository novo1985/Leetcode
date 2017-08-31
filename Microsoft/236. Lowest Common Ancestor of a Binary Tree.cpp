class Solution{
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    //base case:
    if(root == p || root == q || !root) { return root; }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left && right) { return root; }
    else{
      return left? left : right;
    }
  }
};