#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
    }
* Populate each next pointer to point to its next right node. If there is no next right node, the
* next pointer should be set to NULL.
* Initially, all next pointers are set to NULL.
*
* Note:
* You may only use constant extra space.
* You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and
* every parent has two children). ***********/
/* For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL        *************/

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


//solution1: recursive, more than constant space
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if(!root) { return; }
    if(root->left) { root->left->next = root->right; }
    if(root->right){ root->right->next = root->next? root->next->left : nullptr; }//key
    connect(root->left);
    connect(root->right);
  }
};

//solution2: Non-recursion, more than constant space, using queue
class Solution{
public:
  void connect(TreeLinkNode* root){
    if(!root) { return; }
    queue<TreeLinkNode*> q;
    q.push(root);
    q.push(nullptr);
    while(true){
      TreeLinkNode* cur = q.front();
      q.pop();
      if(cur){
        cur->next = q.front();
        if(cur->left){ q.push(cur->left); }
        if(cur->right){ q.push(cur->right); }
      }
      else{
        if(q.size()==0 || q.front() = NULL){ return; }
        q.push(nullptr);
      }
    }
  }
};
/*
class Solution{
public:
  void connect(TreeLinkNode* root){
    if(!root) { return; }
    stack<TreeLinkNode*> s1;
    stack<TreeLinkNode*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
      while(!s1.empty()){
        TreeLinkNode* cur = s1.top();
        s1.pop();
        if(cur->right){ s2.push(cur->right); }
        if(cur->left){ s2.push(cur->left); }
        if(s1.top()){ cur->next = s1.top(); }
        else{ cur->next = nullptr; }
      }
      while(!s2.empty()){
        TreeLinkNode* cur = s2.top();
        s2.pop();
        if(cur->right){ s1.push(cur->right); }
        if(cur->left){ s1.push(cur->left); }
        if(s2.top()){ cur->next = s2.top(); }
        else{ cur->next = nullptr; }
      }
    }
  }
};
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeLinkNode *t = q.front(); q.pop();
                if (i < size - 1) {
                    t->next = q.front();
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }
};

//Solution3: O(1)space!
class Solution{
public:
  void connect(TreeLinkNode* root){
    if(!root) { return; }
    TreeLinkNode* start = root, *cur = nullptr;//start to label level,cur to label node in this level
    while(start->left){
      cur = start;
      while(cur){
        cur->left->next = cur->right;
        if(cur->next){
          cur->right->next = cur->next->left;
        }
        cur = cur->next;
      }
      start = start->left;
    }
  }
};

























