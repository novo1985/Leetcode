/* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.*/



//dfs recursion:
class Solution {
public:
    int sumNumbers(TreeNode* root) {
      int sum = 0;
      vector<int> path;
      dfs(root, path, sum);
      return sum;
    }

    void dfs(TreeNode* node, vector<int>& path, int& sum) {
      //stop condition, next level is empty node!
      if(!node) { return; }

      //any path is start from root!
      path.push_back(node->val);
      if(!node->left && !node->right) {
        // path is finished , we need add path-presented integer into sum
        int n = path.size();
        int temp = 0;
        for(int i = 0; i < n; i++) {
          temp += path[i]*pow(10, n-1-i);
        }
        sum += temp;
     }
     dfs(node->left, path, sum);
     dfs(node->right, path, sum);
     path.pop_back();
    }
};

//easy recursion
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode *root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};










