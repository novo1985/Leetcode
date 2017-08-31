class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(inorder.size() != postorder.size()) {
        return nullptr;
      }
      return builtBinaryTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* builtBinaryTree(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder,
      int p_start, int p_end) {
      if(i_start > i_end || p_start > p_end) {
        return nullptr;
      }
      //root is last element of postorder;
      TreeNode* newroot = new TreeNode(postorder[p_end]);
      //find indices for leftsubtree & rightsubtree
      //1' find index of root in inorder
      int k = i_start;
      for(k = i_start; k <= i_end; k++) {
        if(inorder[k] == postorder[p_end]) {
          break;
        }
      }//now k is the index of root in inorder sequence
      //2' calc leftsubtree & rightsubtree length
      int leftsize = k - i_start;
      int rightsize = i_end - k;
      newroot->left = builtBinaryTree(inorder, i_start, k-1, postorder, p_start, leftsize - 1 + p_start);
      newroot->right = builtBinaryTree(inorder, k+1, i_end, postorder, p_end - rightsize, p_end-1);
      return newroot;
    }
};