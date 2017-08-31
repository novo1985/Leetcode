#include <bits/stdc++.h>
using namespace std;

/* Implement an iterator over a binary search tree (BST). Your iterator will be initialized
 * with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h
 * is the height of the tree. ********/
/*
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/

class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
      TreeNode *cur = root;
      while (cur) {
        s_.push(cur);
        cur = cur->left;
      }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !s_.empty();
    }

    /** @return the next smallest number */
    int next() {
      TreeNode *cur = s_.top();
      s_.pop();
      int res = cur->val;
      cur = cur->right? cur->right : nullptr;

      while (cur) {
        s_.push(cur);
        cur = cur->left;
      }

      return res;
    }

  private:
    stack<TreeNode*> s_;
};


