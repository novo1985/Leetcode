class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) { return nullptr; }
        //find the leftmost node, change as new root, root->left = its parent->right(sibling), root->right = its parent;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(cur){
                s.push(cur);
                cur = cur->left;
        }

        cur = s.top();//new root of the rotated tree
        TreeNode* nroot = cur;
        s.pop();//now the top of the stack is the parent root of current node

        while(!s.empty()){
            cur->right = s.top();
            cur->left = s.top()->right;
            s.pop();
            cur = cur->right;
        }

        return nroot;
    }
};

//iteration
class Solution{
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* cur = root, *parent = nullptr, *right = nullptr;
        while(cur){
            TreeNode* left = cur->left;//temporary store original pointer
            cur->left = right;
            cur->right = parent;
            parent = cur;
            right = cur->right;
            cur = left;
        }
        return parent;
    }
}




