/* input : unsorted array without duplicate*/
/* output: Maximun Binary Tree
 * build BT: 1. Find the root
 *           2. leftsubtree, and rightsubtree
 *               index is important! ******/


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if(nums.empty()) { return nullptr; }
      int n = nums.size();
      TreeNode* root = buildTreeNode(nums, 0, n-1);
      return root;
    }

    TreeNode* buildTreeNode (vector<int>& nums, int start, int end) {
        if(start > end) { return nullptr; }
        int index = findnode(nums, start, end);
        TreeNode* node = index != -1 ? new TreeNode(nums[index]) : nullptr;
        if(node) {
            node->left = buildTreeNode(nums, start, index - 1);
            node->right = buildTreeNode(nums, index+1, end);
        }
        return node;
    }

    int findnode(vector<int>& nums, int start, int end) {//find the maximum number in array, return index
      int nodeval = INT_MIN;
      int index = -1;
      for(int i = start; i <= end; i++) {
        if(nums[i] > nodeval){
          nodeval = nums[i];
          index = i;
        }
      }
      return index;//time complexity: O(n)
    }
};

/* o(n) using stack: new coming node compare with the stack.back() node, if new value > back.val
 *  newnode->left = stack.back(), stack.pop()
 *  if new value < back.val, back->right = newnode
 *  stack will keep descending value order;***************/

class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if(nums.empty()) { return nullptr; }
      deque<TreeNode*> dq;

      for(int i = 0; i < nums.size(); i++) {
        TreeNode* node = new TreeNode(nums[i]);
        while(!dq.empty() && dq.back()->val < node->val) {
          node->left = dq.back();
          dq.pop_back();
        }
        if(!dq.empty()){//now the left node's value bigger than newnode
          dq.back()->right = node;
        }
        dq.push_back(node);
      }
      return dq.front();
    }
};
















