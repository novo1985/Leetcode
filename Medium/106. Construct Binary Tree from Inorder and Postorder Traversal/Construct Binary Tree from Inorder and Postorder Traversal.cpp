#include < bits/stdc++.h>

/* Given inorder and postorder traversal of a tree, construct the binary tree. */

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
}

/* preorder : 1)root;  2)leftsubtree;  3) rightsubtree
 * inorder :  1)leftsubtree;  2)root;  3) rightsubtree
 * postorder: 1)leftsubtree;  2)rightsubtree;  3)root ****/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(inorder.size() != postorder.size()) { return nullptr; }
      return buildbinary(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* buildbinary(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder,
                                          int p_start, int p_end){
      if(i_start > i_end || p_start > p_end) { return nullptr;}
      TreeNode *root = new TreeNode(postorder[p_end]);
      //get root index of inorder to divide leftsubtree and rightsubtree
      int k = i_start;
      for(k = i_start; k <= i_end; k++){
        if(inorder[k] == postorder[p_end]) break;
      }
      int lefttreesize = k - i_start;
      int righttreesize = i_end - k;
      // k is the index of root of inorder, index is changed, using length/size
      root->left = buildbinary(inorder, i_start, k-1, postorder, p_start, p_start + lefttreesize-1);
      root->right = buildbinary(inorder, k+1, i_end, postorder, p_end - righttreesize, p_end-1);
      return root;
    }
};



