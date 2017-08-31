#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]                                             **************/
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

struct node{
  TreeNode *node;
  int level;
  Node(TreeNode* n, int x): node(n), level(x){}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > ret;
        //ret.clear();
        if (root == NULL)
            return ret;
        queue<Node> q;
        q.push(Node(root, 0));
        int curLevel = -1;
        vector<int> a;
        while(!q.empty())
        {
            Node node = q.front();
            if (node.node->left)
                q.push(Node(node.node->left, node.level + 1));
            if (node.node->right)
                q.push(Node(node.node->right, node.level + 1));
            if (curLevel != node.level)
            {
                if (curLevel != -1)
                {
                    if (curLevel % 2 == 1)
                        reverse(a.begin(), a.end());

                    ret.push_back(a);
                }
                a.clear();
                curLevel = node.level;
            }
            a.push_back(node.node->val);
            q.pop();
        }
        if (curLevel % 2 == 1)
            reverse(a.begin(), a.end());
        ret.push_back(a);
        return ret;
    }
};

//bfs: two stack! stack last-in-first-out
class Solution{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) { return res; }
    stack<TreeNode*> s1; // store left->right
    stack<TreeNode*> s2; // store right->left
    vector<int> sol;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
      while(!s1.empty()){
        TreeNode* cur = s1.top();
        s1.pop();
        if(cur->left){ s2.push(cur->left); }
        if(cur->right) { s2.push(cur->right); }
        sol.push_back(cur->val);
      }
      if(!sol.empty()) { res.push_back(sol); }
      sol.clear();
      while(!s2.empty()){
        TreeNode *cur = s2.top();
        s2.pop();
        if(cur->right) { s1.push(cur->right); }
        if(cur->left) { s1.push(cur->left); }
        sol.push_back(cur->val);
      }
      if(!sol.empty()) { res.push_back(sol);}
      sol.clear();
    }
    return res;
  }
};









