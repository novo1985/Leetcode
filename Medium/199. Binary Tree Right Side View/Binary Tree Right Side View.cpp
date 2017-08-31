#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, imagine yourself standing on the right side of it, return the values of
 * the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4]. ************/

struct Node{
  TreeNode* tnode;
  int level;
  Node(TreeNode* n, int x):tnode(n), level(x){}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> res;
      if(!root){ return res;}
      stack<Node> s;
      s.push(Node(root, 0));
      int curlevel = 0;

      while(!s.empty()){
        Node temp = s.top();
        TreeNode *cur = temp.tnode;
        s.pop();
        if(cur->left) { s.push(Node(cur->left, temp.level+1)); }
        if(cur->right) { s.push(Node(cur->right, temp.level+1)); }
        if(temp.level == curlevel) { res.push_back(temp.tnode->val); curlevel++;}
      }
      return res;
    }
};

//solution2: queue
class Solution{
public:
  vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if(!root) { return res; }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
      res.push_back(q.back()->val);
      int n = q.size();
      for(int i = 0; i < n; i++){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left) { q.push(temp->left); }
        if(temp->right) { q.push(temp->right); }
      }
    }
    return res;
  }
};

















