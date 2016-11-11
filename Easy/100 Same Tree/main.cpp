#include <iostream>

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
  TreeNode(void){}
};
class TwoBinaryTree{
public:
  //constructor1
  TwoBinaryTree(TreeNode* root1, TreeNode* root2){}
  //constructor2
  TwoBinaryTree(){}
  //de-constructor
  ~TwoBinaryTree(void){}

  // checking whether two binary trees are same or not
  bool isSameTree(TreeNode* p, TreeNode* q);
};

bool TwoBinaryTree::isSameTree(TreeNode* p, TreeNode* q) {
  if(!p && !q){
    return true;
  }
  if((!p && q) ||(p && !q)){
    return false;
  }
  if(p->val != q->val){
    return false;
  }
  /**if(p->val == q->val){
       if(!p->left && !p->right && !q->left && !q->right){
           return true;
       }
       if((p->left && q->left) && (!p->right && !q->right)){
           return isSameTree(p->left,q->left);
       }
       if((p->right && q->right) && (!p->left && !q->left)){
           return isSameTree(p->right,q->right);
       }
       if(p->right && q->right && p->right && q->right){
          bool l = isSameTree(p->left,q->left);
          bool r = isSameTree(p->right,q->right);
          if (l&&r){
              return true;
          }
       }
   }*/
  bool l = isSameTree(p->left,q->left);
  bool r = isSameTree(p->right,q->right);
  if (l&&r){
    return true;
  }
  else return false;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}