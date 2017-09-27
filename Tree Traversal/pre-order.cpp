//preorder: root, left, right
//preorder-iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) {
          return res;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
          TreeNode* cur = s.top();
          s.pop();
          res.push_back(cur->val);
          if(cur->right) { s.push(cur->right); }
          if(cur->left) {s.push(cur->left); }
        }
        return res;
    }
};

//preorder-iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      helper(root, res);
      return res;
    }
    void helper(TreeNode* node, vector<int>& res) {
      if(!node) { return; }
      res.push_back(node->val);
      helper(node->left, res);
      helper(node->right, res);
    }
};










