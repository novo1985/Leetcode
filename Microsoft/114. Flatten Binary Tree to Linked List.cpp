//preorder-recursion
class Solution {
public:
    void flatten(TreeNode* root) {
      if(!root) { return; }
      flatten(root->left);
      flatten(root->right);
      TreeNode* temp = root->right;
      root->right = root->left;
      root->left = nullptr;
      while(root->right) {
        root = root->right;
      }
      root->right = temp;
    }
};

//preorder_iteration
class Solution {
public:
    void flatten(TreeNode* root) {
      if(!root) { return; }
      stack<TreeNode*> s;
      s.push(root);
      while(!s.empty()) {
        TreeNode* cur = s.top();
        s.pop();
        if(cur->left){
          TreeNode* temp = cur->left;
          while(temp->right) {
            temp = temp->right;
          }
          temp->right = cur->right;
          cur->right = cur->left;
          cur->left = nullptr;
        }
        if(cur->right) {
          s.push(cur->right);
        }
      }
    }
};

//postorder-recursion
class Solution {
public:
    void flatten(TreeNode* root) {
      if(!root) { return; }//base case empty node
      flatten(root->right);
      flatten(root->left);
      root->right = prev;
      root->left = nullptr;
      prev = root;
    }
private:
    TreeNode* prev = nullptr;
};





