//post-order: iteration
//two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) { return res; }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;//store post-order sequence (left,right, root)
        s1.push(root);
        while(!s1.empty()) {
          TreeNode* cur = s1.top();
          s1.pop();
          s2.push(cur);
          if(cur->left) { s1.push(cur->left); }
          if(cur->right) { s1.push(cur->right); }
        }
        while(!s2.empty()) {
          TreeNode* cur = s2.top();
          s2.pop();
          res.push_back(cur->val);
        }
        return res;
    }
};
//one stack: (left, right, root), does not change the tree
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) { return res; }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* stop = root;//important!
        while(!s.empty()) {
          TreeNode* cur = s.top();
          if((!cur->left && !cur->right) || cur->left == stop || cur->right == stop) {
            res.push_back(cur->val);
            s.pop();
            stop = cur;
          }else{
            if(cur->right) { s.push(cur->right); }
            if(cur->left) { s.push(cur->left); }
          }
        }
        return res;
    }
};

//recursion:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* node, vector<int>& res) {
      if(!node) {
        return;
      }
      helper(node->left, res);
      helper(node->right, res);
      res.push_back(node->val);
    }
};












