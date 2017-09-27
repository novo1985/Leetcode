class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      TreeNode* res = nullptr;
      while(root) {
        if(root->val > p->val) {
          res = root;
          root = root->left;
        }else {
          root = root->right;
        }
      }
      return res;
    }


//recursion
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      if(!root) { return nullptr; }
      if(root->val <= p->val) {
        return inorderSuccessor(root->right, p);
      }else {
        TreeNode *res = inorderSuccessor(root->left, p);
        return res? res : root;
      }
    }
};





