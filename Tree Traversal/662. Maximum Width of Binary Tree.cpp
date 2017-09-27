class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       if(!root) { return 0; }
       int res = 0;
       queue<pair<TreeNode*, int>> q;
       q.push(make_pair(root, 1));
       while(!q.empty()) {
           int n = q.size();
           int start = q.front().second, end = start;
           for(int i = 0; i < n; i++) {
               TreeNode* temp = q.front().first;
               end = q.front().second;
               q.pop();
               if(temp->left) { q.push(make_pair(temp->left, 2*end)); }
               if(temp->right) { q.push(make_pair(temp->right, 2*end + 1)); }
               res = max(res, end - start + 1);
           }
       }
        return res;
    }
};