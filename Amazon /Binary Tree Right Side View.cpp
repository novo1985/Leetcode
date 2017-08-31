class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(!root) { return res; }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          int n = q.size();
          vector<int> level;
          for(int i = 0; i < n; i++){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) { q.push(cur->left); }
            if(cur->right) { q.push(cur->right); }
            level.push_back(cur->val);
          }
          res.push_back(level.back());
        }

        return res;
    }
};