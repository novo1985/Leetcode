/* target -= target - node->value, recursion! */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) { return false; }
        if(!root->left && !root->right) { return root->val == sum; }
        bool l = hasPathSum(root->left, sum - root->val);
        bool r = hasPathSum(root->right, sum - root->val);
        return l || r;
    }
};













