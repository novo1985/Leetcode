#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Given a binary tree, return all root-to-leaf paths. */

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      if(root) { dfs(root, "", res); }
      return res;
    }

    void dfs(TreeNode* root, string path, vector<string>& res){
      path += to_string(root->value);
      if(!root->left && !root->right) { res.push_back(path); }
      else{
        if(root->left){ dfs(root->left, path + "->", res);}
        if(root->right){ dfs(root->right, path + "->", res);}
      }
    }

};