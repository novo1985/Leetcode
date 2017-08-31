#include <bits/stdc++.h>
using namespace std;

/*Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL  ********/


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
//solution1: Recursion, more than constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p;
        if (root->left) root->left->next = root->right ? root->right : p;
        connect(root->right);
        connect(root->left);
    }
};




//solution2: non-recursive o(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
      if(!root) { return; }
      TreeLinkNode* leftmost = root;
      while(leftmost){
        TreeLinkNode *cur = leftmost;
        while(cur && !cur->left && !cur->right){ cur = cur->next; }
        if(!cur) { return; }
        leftmost = cur->left ? cur->left : cur->right;

      }
    }
};











