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
    string serialize(TreeNode* root) {
        string res;
        if(!root) { return res; }
        //using level traveral
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
          int n = q.size();
          for(int i = 0; i < n; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur){
              res += to_string(cur->val) + " ";
              q.push(cur->left);
              q.push(cur->right);
            }else{
              res += "null ";
            }
          }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) { return nullptr; }
        istringstream in(data);
        string str;
        in >> str;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        TreeNode* cur = nullptr;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            in >> str;
            if(str.empty()) { break; }
            if(str != "null") {
              cur = new TreeNode(stoi(str));
              temp->left = cur;
              q.push(tem->left);
            }//else temp->left = nullptr;
            in >> str;
            if(str != "null") {
              cur = new TreeNode(stoi(str));
              temp->right = cur;
              q.push(tem->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));