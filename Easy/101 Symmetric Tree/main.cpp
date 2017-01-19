#include <iostream>

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
  bool ismirror(TreeNode* p, TreeNode* q){
    if(!p && !q){return true; }
    else if((!p && q) || (p && !q) ){return false;}
    else if(p->val != q->val){ return false;}
    bool LR = ismirror(p->left, q->right);
    bool RL = ismirror(p->right, q->left);
    if(LR && RL){return true;}
    else return false;
  }
  bool isSymmetric(TreeNode* root){
    if(!root ){return true;}
    bool sym = ismirror(root->left, root->right);
    return sym;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}