#include <bits/stdc++.h>
using namespace std;

/* Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible. It can have between 1 and 2h
nodes inclusive at the last level h.*/

//solution1: recursion, binary divide
class Solution {
public:
    int countNodes(TreeNode* root) {
      if(!root) { return 0; }
      int depth = 0;
      TreeNode* cur = root;
      while(cur->left) { depth++; cur = cur->left; }
      return countNumbers(root, depth);
    }
    int countNumbers(TreeNode* root, int depth){
      int res;
      if(!root) { res = 0;}
      if(!root->left && !root->right) { res = 1; }
      if(root->left && !root->right) { res = 2; }
      else{
        if(equal_Depth(root->left, root->right)){
          res = 1 + pow(2, depth) - 1;
          res += countNumbers(root->right, depth - 1);
        }
        if(!equal_Depth(root->left, root->right)){
          res = 1 + pow(2, depth -1) - 1;
          res += countNumbers(root->left, depth - 1);
        }
      }
      return res;
    }

    bool equal_Depth(TreeNode* n1, TreeNode* n2){
      int d1 = 0, d2 = 0;
      TreeNode *temp1 = n1, *temp2 = n2;
      while(temp1 && temp1->left){
        d1++;
        temp1 = temp1->left;
      }
      while(temp2 && temp2->left){
        d2++;
        temp2 = temp2->left;
      }
      if(d1 == d2) { return true;}
      return false;
    }
};

//solution2: recursion
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};




