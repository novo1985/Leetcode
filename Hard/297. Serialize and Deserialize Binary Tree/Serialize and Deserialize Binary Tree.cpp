/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
      TreeNode* cur = nullptr;
      q.push(root);
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