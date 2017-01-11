#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

// binary tree: traversal each node (bottom-up) in level order, the return value is vector of int vector
// BFS(using queue to store nodes in each level)
class Solution{
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root){
    vector<vector<int>> res;
    if(!root){ return res;}
    //create a queue to store node in level order
    queue<TreeNode*> q;
    q.push(root);

    // also need to label the level of node, we create a pair container
    /*int level = 0;
    pair<TreeNode*, int> nodes_level;
    vector<pair<TreeNode*, int>> nodes_with_label;
    nodes_with_label.push_back(make_pair(root,0));
    TreeNode* curr;
    while(!curr_node.empty()){
      curr = curr_node.front();
      curr_node.pop();
      nodes_with_label.push_back(make_pair(curr,level));
      if(curr->left){
        curr_node.push(curr->left);
        level++;
      }
      if(curr->right){
        curr_node.push(curr->right);
        level++;
      }
    }
    for(int i = 0; i < level; i++){
      vector<int> TreeLevel;
      for(auto iter = nodes_with_label.begin(); iter != nodes_with_label.end(); iter++){
        if(iter->second == i){
          TreeLevel.push_back(iter->first->val);
        }
      }
      res.push_back(TreeLevel);
    }
    return res;
     */
    while(!q.empty()){
      int n = q.size();
      vector<int> curr_level;
      for(int i = 0; i < n; i++){
        TreeNode* curr = q.front();
        q.pop();
        curr_level.push_back(curr->val);
        if(curr->left){
          q.push(curr->left);
        }
        if(curr->right){
          q.push(curr->right);
        }
      }
      res.push_back(curr_level);
    }
    reverse(res.begin(), res.end());
    return res;
  }

};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}