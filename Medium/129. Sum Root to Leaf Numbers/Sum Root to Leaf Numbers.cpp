#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a
 * number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. ******/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//solution1: extra space to store all path;
class Solution{
public:
  int sumNumbers(TreeNode* root){
    vector<vector<int>> allpath;
    vector<int> path;
    dfs(allpath, path, root);
    int sum = 0;
    for(int i = 0; i < allpath.size();i++){
      int temp = 0;
      for(int j = 0; j < allpath[i].size(); j++){
        temp += allpath[i][j] * pow(10, allpath[i].size()-1-j);
      }
      sum += temp;
    }
    return sum;
  }
  void dfs(vector<vector<int>>& allpath, vector<int>& path, TreeNode* root){
    if(!root) { return; }
    path.push_back(root->val);
    if(!root->left && !root->right){
      allpath.push_back(path);
    }
    else{
      dfs(allpath, path, root->left);
      dfs(allpath, path, root->right);
    }
    path.pop_back();
  }
};

//solution2: just store int value
class Solution{
public:
  int sumNumbers(TreeNode* root){
    int pathsum = 0;
    return dfs(pathsum, root);
  }
  int dfs(int pathsum, TreeNode* root){
    if(!root){ return pathsum; }
    //int temp = pathsum;
    pathsum = pathsum * 10 + root->val;
    if(!root->left && !root->right) { return pathsum;}
    else{
      return dfs(pathsum,root->left) + dfs(pathsum,root->right);
    }
  }
};

//solution3:
int sumNumbers(TreeNode *root) {
    int sum=0, path =0;
    GenerateSum(root, sum, path);
    return sum;
}
void GenerateSum(TreeNode *root, int& sum, int path)
{
    if(root == NULL) return;
    path = path*10 + root->val;
    if(root->left == NULL && root->right == NULL)
    {
         sum += path;
         return;
    }
    GenerateSum(root->left, sum, path);
    GenerateSum(root->right, sum, path);
}








