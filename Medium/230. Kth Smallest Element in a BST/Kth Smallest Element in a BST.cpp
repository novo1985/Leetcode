#include <bits/stdc++.h>
using namespace std;

/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest
frequently? How would you optimize the kthSmallest routine?     **********************************/

//solution1: recursion
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
      if(!root) { return -1;}
      int n = countNode(root->left);
      if(n + 1 < k){
        return kthSmallest(root->right, k-n-1);
      }
      if(n+1 == k){ return root->val;}
      if(n == k){
        TreeNode* cur = root->left;
        while(cur->right){
          cur = cur->right;
        }
        return cur->val;
      }
      if(n > k) {
        return kthSmallest(root->left, k);
      }
    }

    int countNode(TreeNode* node){
      int nums = 0;
      if(!node) {return nums;}
      stack<TreeNode*> s;
      s.push(node);
      while(!s.empty()){
        TreeNode* cur = s.top();
        nums++;
        s.pop();
        if(cur->right){s.push(cur->right);}
        if(cur->left){s.push(cur->left);}
      }
      return nums;
    }
};



//inorder
class Solution {
public:
   int kthSmallest(TreeNode* root, int k) {
       int cnt = 0;
       TreeNode *p = root;
       stack<TreeNode *> st;
       while (p != NULL || !st.empty()) {
          if (p != NULL) {
              st.push(p);
              p = p->left;
          } else {
              p = st.top();
              st.pop();
              if (++cnt == k) return p->val;
              p = p->right;
          }
       }
   }
};






