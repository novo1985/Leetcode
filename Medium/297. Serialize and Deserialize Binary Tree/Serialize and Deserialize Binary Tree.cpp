#include <bits/stdc++.h>
using namespace std;

/* Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how
 * your serialization/deserialization algorithm should work. You just need to ensure that a binary
 * tree can be serialized to a string and this string can be deserialized to the original tree
 * structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]"   *****************************/

class Codec {
public:

    // Encodes a tree to a single string.
    /*solution: tree traverse: pre-order, in-order or post-order, level-traverse
     *level-traverse is better, nums[i]->left is nums[2*i+1] nums[i] -> right is nums[2*i+2] ***/
    string serialize(TreeNode* root) {
      string res;
      if(!root) { return res;}
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int len = q.size();
        for(int i = 0; i < len; i++){
          TreeNode* cur = q.front();
          q.pop();
          if(cur){
              q.push(cur->left);
              q.push(cur->right);
              res += to_string(cur->val) + " ";
          }else{
              res += "null ";
          }
        }
      }
      res.pop_back();//delete last " "
      return res;
    }

    // Decodes your encoded data to tree.
    /*root is first substring between '[' and ',' or ']'
     *nums[i]->left is nums[2*i+1] nums[i] -> right is nums[2*i+2] ****/
    TreeNode* deserialize(string data) {
      if(data.empty()){return nullptr;}
      //vector<int> nums;
      queue<TreeNode*> q;
      istringstream in(data);
      string val;
      in >> val;
      TreeNode* root = new TreeNode(stoi(val));
      TreeNode* cur = root;
      q.push(cur);
      while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        in >> val;
        if(val.empty()){ break; } //no val, end of the string
        if(val != "null") {
          cur = new TreeNode(stoi(val));
          q.push(cur);
          temp->left = cur;
        }//else(val == "null") temp->left == "null", already defined in constructor
        in >> val;
        if(val.empty()){ break; }//no val, end of the string
        if(val != "null"){
          cur = new TreeNode(stoi(val));
          q.push(cur);
          temp->right = cur;
        }
      }
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));












