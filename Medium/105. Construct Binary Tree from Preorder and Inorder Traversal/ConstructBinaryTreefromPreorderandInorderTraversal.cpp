#include <iostream>
#include <vector>
//#include <cmath>
using namespace std;

/* Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.   *****************/
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

};

/* preorder : 1)root;  2)leftsubtree;  3) rightsubtree
 * inorder :  1)leftsubtree;  2)root;  3) rightsubtree
 * postorder: 1)leftsubtree;  2)rightsubtree;  3)root ****/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.size() != inorder.size()) { return nullptr; }
      return binaryTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

    }
    TreeNode* binaryTree(vector<int>& preorder, int p_start, int p_end,
                                vector<int>& inorder, int i_start, int i_end){
      if(p_start > p_end || i_start > i_end) { return nullptr; }
      //In_order: left substree, root, right subtree
      //step1, find index of root, divide inorder into [left, root, right]
      int k = 0; // index for root
      for(int k = i_start; k <= i_end; k++){
        if(inorder[k] == preorder[p_start]){
          break;
        }
      }// we get the value of root index = i
      TreeNode *root = new TreeNode(preorder[p_start]);
      //subtree size equal
      root->left = binaryTree(preorder, p_start+1, p_start + k - i_start, inorder, i_start, k-1);
      root->right = binaryTree(preorder,p_start + k - i_start + 1, p_end, inorder, k+1, i_end);
      return root;
    }
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder,
             int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};



