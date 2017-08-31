#include <bits/stdc++.h>
using namespace std;

/* Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 * Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).
*
root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7    Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7                   ********************************************************/

//solution1: recursion
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(!root) { return root;}
      if(root->val > key){ // the target node be in the left subtree
        root->left = deleteNode(root->left, key);
      }else if(root->val < key){ // the target node be in the right subtree
        root->right = deleteNode(root->right, key);
      }else{ // root->val == key
        if(!root->left || !root->right){
          root = root->left ? root->left : root->right;
        }
        else{// find the next smaller node(biggest one in the left tree)
          TreeNode* prev = root;
          TreeNode* cur = root->left;
          while(cur->right){
            prev = cur;
            cur = cur->right;
          }
          root->val = cur->val;
          if(cur == root->left){
              prev->left = cur->left ? cur->left : nullptr;
          }else{
              prev->right = cur->left ? cur->left : nullptr;
          }
          cur->left = nullptr;
        }
      }
      return root;
    }
};
//solution2: recursion
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(!root) { return root;}
      if(root->val > key){
        root->left = deleteNode(root->left, key);
      }else if(root->val < key){
        root->right = deleteNode(root->right, key);
      }
      else{
        if(!root->left || !root->right) {
          root = root->left ? root->left : root->right;
        }
        else{
          TreeNode* cur = root->left;
          while(cur->right) {cur = cur->right;}
          root->val = cur->val;
          root->left = deleteNode(root->left, cur->val);
        }
      }
      return root;
    }
};

//solution3: iteration
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

    }
};



















