//inorder: left, root, right;

//inorder-itertion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) { return res; }
        stack<TreeNode*> s;
        TreeNode* cur = root
        while(!s.empty() || cur) {
          while(cur){
            s.push(cur);
            cur = cur->left;
          }
          if(!cur){
            cur = s.top();
            res.push_back(cur->val);
            s.pop();
            cur = cur->right;
          }
        }
        return res;
    }
};

//inorder-recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* node, vector<int>& res){
        if(!node) { return; }
        helper(node->left, res);
        res.push_back(node->val);
        helper(node->right, res);
    }
};







