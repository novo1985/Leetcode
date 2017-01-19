#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/****
 * level order traversal of binary tree ----BFS(queue), but need set the level pointer
 * ***/
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
/****
  // construct a new structure node with level
  struct Nodelevel{
    TreeNode* node;
    int level;
    Nodelevel(TreeNode* cur, int x):node(cur), level(x){}
  };

public:

  vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> res;
    if(!root){ return res;}
    queue<Nodelevel> node_q; // queue for BFS
    node_q.push(Nodelevel(root,0));

    while(!node_q.empty()) {
      // how to store TreeNode value by level?
      TreeNode* cur = node_q.front().node; // get the current Treenode
      int cur_level = node_q.front().level; //index of res
      node_q.pop();

      if(cur_level == res.size()){res.push_back(vector<int>(0,0));} // ?

      res[cur_level].push_back(cur->val);

      if (cur->left) { node_q.push(Nodelevel(cur->left, cur_level+1));}
      if (cur->right) { node_q.push(Nodelevel(cur->right, cur_level+1));}
    }
    return res;
  }
   ****/
public:
  vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root){ return res;}
    queue<TreeNode*> node_q;
    node_q.push(root);
    node_q.push(nullptr);
    int cur_level = 0;
    while(!node_q.empty()){
      TreeNode* cur = node_q.front();
      node_q.pop();
      if(!cur){
        cur_level++;
        if(!node_q.empty()) node_q.push(nullptr);
        continue;
      }
      if(cur_level == res.size()){
        res.push_back(vector<int>(0,0));
      }
      res[cur_level].push_back(cur->val);
      if(cur->left){node_q.push(cur->left);}
      if(cur->right){node_q.push(cur->right);}
    }
    return res;
  }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}