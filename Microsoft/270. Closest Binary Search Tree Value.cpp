

//binary search, just like array. iteration
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
      int res = root->val;//initailization
      TreeNode* cur = root;
      while(cur){
        if(abs(res - target) >= abs(cur->val - target)){//if new closer node, update
          res = cur->val;
        }
        cur = cur->val > target ? cur->left: cur->right;//binary search;
      }

      return res;
    }
};

//recursion
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
      int res = root->val;
      TreeNode* next = target > root->val ? root->right : root->left;
      if(!next) { return res; }
      int subres = closestValue(next, target);
      return abs(res-target) > abs(subres-target)? subres : res;
    }
};



