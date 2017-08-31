#include <iostream>
#include <vector>
using namespace std;

/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(Nullptr), right(Nullptr){}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      //root value = nums[mid]
      return toBST(nums, 0, nums.size()-1);
    }
    TreeNode* toBST(vector<int>& nums, int start, int end){
      //case1: nums is empty
      if(start > end) { return NULL;}
      int mid = start + (end - start)/2;
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = TreeNode* toBST(nums, start, mid-1);
      root->right = TreeNode* toBST(nums, mid+1, end);
      return root;
    }
};