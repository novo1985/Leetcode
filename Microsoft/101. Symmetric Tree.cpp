/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).*/

//solution: recursion!
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if(!root) { return true; }
      return helper(root->left, root->right);
    }

    bool helper(TreeNode* p, TreeNode* q){
      //stop or return condition1: p != q
      if((!p && q) || (p && !q) || p && q && p->val != q->val) { return false; }
      //stop or return condition2: p == q but all are nullptr
      if(!p && !q) { return true; }

      //recursion:
      return helper(p->left, q->right) && helper(p->right, q->left);
    }
};


//iteration! BFS queue, check each row, left subtree & right subtree
class Solution{
public:
    bool isSymmetric(TreeNode* root) {
      if(!root) { return true; }
      queue<TreeNode*> q1, q2;//q1 for left subtree, q2 for right subtree;

      //may be push the nullptr, it does not matter, we will deal with this later
      q1.push(root->left);
      q2.push(root->right);

      while(!q1.empty() && !q2.empty()) {
        TreeNode* left = q1.front();
        TreeNode* right = q2.front();
        q1.pop();
        q2.pop();
        //check isSame?
        if((!left && right) || (left && !right)) {
          return false;
        }
        if(!left && !right) {continue;}
        if(left && right) {
          if(left->val != right->val) { return false; }
          else {
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
          }
        }
      }
      return true;
    }
};









