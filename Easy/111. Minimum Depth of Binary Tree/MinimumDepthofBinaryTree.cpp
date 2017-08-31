#include <iostream>
using namespace std;

/*Given a binary tree, find its minimum depth.
 *The minimum depth is the number of nodes along the shortest path from the root node
 *down to the nearest leaf node.*/

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(Nullptr), right(Nullptr){}
};

class Solution{
public:
  int minDepth(TreeNode* root){
    if(!root){ return 0;}
    int left_min = minDepth(root->left);
    int right_min = minDepth(root->right);
    if(left_min == 0 && right_min == 0){
      return 1;
    }
    if(left_min == 0){
      left_min = INT_MAX;
    }
    if(right_min == 0){
      right_min = INT_MAX;
    }
    return min(left_min, right_min) + 1;
  }
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;

        if (root->left == NULL) return minDepth(root->right) + 1;
        else if (root->right == NULL) return minDepth(root->left) + 1;
        else return 1 + min(minDepth(root->left), minDepth(root->right));
    }

};