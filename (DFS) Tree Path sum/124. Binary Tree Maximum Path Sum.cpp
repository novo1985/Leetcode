/* Given a binary tree, find the maximum path sum.

 * For this problem, a path is defined as any sequence of nodes from some starting node to any
 * node in the tree along the parent-child connections. The path must contain at least one node
 * and does not need to go through the root.    *************/


/* Disect question:
 * 包括root的最大sum的path：root + 左侧最大sum的path + 右侧最大sum的path
 * root->left
 * root->right
 * check each node!!! find the maxsum            *******************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct NodeInfo{
  int lmaxsum = INT_MIN;
  int rmaxsum = INT_MIN;
  int path = INT_MIN;
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
      int maxres = INT_MIN;
      NodeInfo info = helper(root, maxres);
      return maxres;
    }

    NodeInfo helper(TreeNode* root, int& maxres) {
      NodeInfo info;
      //base case
      if(!root) {
        info.lmaxsum = 0;
        info.rmaxsum = 0;
        info.path = 0;
        maxres = 0;
        return info;
      }
      if(!root->left && !root->right) {
        info.lmaxsum = 0;
        info.rmaxsum = 0;
        info.path = root->val;
      }
      else {
        if(root->left) {
            info.lmaxsum = max(helper(root->left, maxres).lmaxsum, helper(root->left, maxres).rmaxsum) > 0 ?
            max(helper(root->left, maxres).lmaxsum, helper(root->left, maxres).rmaxsum) + root->left->val : root->left->val;
        }else {
            info.lmaxsum = 0;
        }
        if(root->right) {
            info.rmaxsum = max(helper(root->right, maxres).lmaxsum, helper(root->right, maxres).rmaxsum) > 0 ?
           max(helper(root->right, maxres).lmaxsum, helper(root->right, maxres).rmaxsum) + root->right->val : root->right->val;
        }else {
            info.rmaxsum = 0;
        }

        info.path = root->val + (info.lmaxsum > 0? info.lmaxsum : 0) + (info.rmaxsum > 0? info.rmaxsum : 0);
      }

      maxres = max(maxres, info.path);
      return info;
    }
};

//
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }

    int dfs(TreeNode* root, int& maxPath) {//dfs function only return maxpath from root to leaf, not every node needed
        if(!root) { return 0;}
        int left = max(0, dfs(root->left, maxPath));//
        int right = max(0, dfs(root->right, maxPath));
        maxPath = max(maxPath, left + right + root->val);//return value
        return root->val + max(left, right);
    }
};

