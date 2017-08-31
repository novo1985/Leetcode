class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) { return res; }
        stack<TreeNode*> s1;//print:left to right
        stack<TreeNode*> s2;//print right to left
        vector<int> temp;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
          while(!s1.empty()){
            TreeNode *cur = s1.top();
            s1.pop();
            temp.push_back(cur->val);
            if(cur->left) { s2.push(cur->left); }
            if(cur->right) { s2.push(cur->right); }
          }
          res.push_back(temp);
          temp.clear();
          while(!s2.empty()) {
            TreeNode *cur = s2.top();
            s2.pop();
            temp.push_back(cur->val);
            if(cur->right) { s1.push(cur->right); }
            if(cur->left) { s1.push(cur->left); }
          }
          res.push_back(temp);
          temp.clear();
        }
        return res;
    }
};