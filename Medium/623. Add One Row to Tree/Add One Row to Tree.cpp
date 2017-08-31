#include <bits/stdc++.h>
using namespace std;

/* Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with
 value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1,
create two tree nodes with value v as N's left subtree root and right subtree root. And N's
original left subtree should be the left subtree of the new left subtree root, its original
right subtree should be the right subtree of the new right subtree root. If depth d is 1 that
means there is no depth d-1 at all, then create a tree node with value v as the new root of
the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input:
A binary tree as following:
       4
     /   \
    2     6
   / \   /
  3   1 5

v = 1

d = 2

Output:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5

Example 2:
Input:
A binary tree as following:
      4
     /
    2
   / \
  3   1

v = 1

d = 3

Output:
      4
     /
    2
   / \
  1   1
 /     \
3       1*/

//solution1: recursion
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
      if (d==1){
        TreeNode* node = new TreeNode(v);
        node->left = root;
        return node;
      }
      DFS_insert(root, 1, v, d);//
      return root;
    }
    void DFS_insert(TreeNode *node, int depth, int v, int d){
      if(!node) { return; }
      if( depth == d-1){ // the parent nodes of new nodes
        TreeNode *left = node->left; //store the left_subtree;
        TreeNode *n_l = new TreeNode(v);
        node->left = n_l;
        n_l->left = left;
        TreeNode *right = node->right;
        TreeNode *n_r = new TreeNode(v);
        node->right = n_r;
        n_r->right = right;
      }else{
        DFS_insert(node->left, depth+1, v, d);
        DFS_insert(node->right, depth+1, v, d);
      }
    }
};

//Solution2: stack, DFS
struct Node{
  TreeNode* node;
  int depth;
  Node(TreeNode* n, int d): node(n), depth(d){}
};
class Solution{
public:
  TreeNode* addOneRow(TreeNode* root, int v, int d){
    if(d==1){
      TreeNode* n = new TreeNode(v);
      n->left = root;
      return n;
    }
    stack<Node> s;
    s.push(Node(root, 1));
    while(!s.empty()){
      Node n = s.top();
      s.pop();
      if(!n.node){ continue; }//avoid to check nullptr
      if(n.depth == d-1){//parent nodes of insertion nodes
        TreeNode* left = n.node->left;
        TreeNode* right = n.node->right;
        TreeNode *n_l = new TreeNode(v);
        TreeNode *n_r = new TreeNode(v);
        n.node->left = n_l;
        n_l->left = left;
        n.node->right = n_r;
        n_r->right = right;
      }else{
        s.push(Node(n.node->left, n.depth+1));
        s.push(Node(n.node->right, n.depth+1));
      }
    }
    return root;
  }
};


//solution3:BFS queue

















