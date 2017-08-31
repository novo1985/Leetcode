/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
      if(!root) { return; }
      TreeLinkNode *start = root;//each level head node;
      TreeLinkNode *head = nullptr;//each level head; to update the start pointer
      TreeLinkNode *cur = nullptr;//go through each level node;
      while(start) {
        while(start){
          if(start->left) {
            if(cur) {
              cur->next = start->left;
            }else {
              head = start->left;
            }
            cur = start->left;//move the cur pointer
          }
          if(start->right) {
            if(cur){
              cur->next = start->right;
            }else {
              head = start->right;
            }
            cur = start->right;
          }
          start = start->next;
        }
        start = head;
        cur = nullptr;
        head = nullptr;
    }
  }
};