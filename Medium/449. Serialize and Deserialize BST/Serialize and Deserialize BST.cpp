#include <bits/stdc++.h>
using namespace std;

/* preorder : root; left; right */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      ostringstream out;
      serilization(root, out);
      return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      istringstream in(data);
      return deserialization(in);
    }

private:
  void serilization(TreeNode* root, ostringstream &out){
    if(root) {
        out << root->val << ' ';
        serilization(root->left, out);
        serilization(root->right, out);
    }
    else{
        out << "# ";
    }
  }
  TreeNode* deserialization(istringstream &in){
    string val;
    in >> val;
    if(val == "#"){ return nullptr; }
    TreeNode *node = new TreeNode(stoi(val));
    node->left = deserialization(in);
    node->right = deserialization(in);
    return node;
  }
};



// Non-recursion
class Codec {
public:
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    ostringstream out;
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode *t = q.front(); q.pop();
        if (t) {
            out << t->val << ' ';
            q.push(t->left);
            q.push(t->right);
        } else {
            out << "# ";
        }
    }
    return out.str();
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    istringstream in(data);
    queue<TreeNode*> q;
    string val;
    in >> val;
    TreeNode *res = new TreeNode(stoi(val)), *cur = res;
    q.push(cur);
    while (!q.empty()) {
        TreeNode *t = q.front(); q.pop();
        if (!(in >> val)) break;
        if (val != "#") {
            cur = new TreeNode(stoi(val));
            q.push(cur);
            t->left = cur;
        }
        if (!(in >> val)) break;
        if (val != "#") {
            cur = new TreeNode(stoi(val));
            q.push(cur);
            t->right = cur;
        }
    }
    return res;
}
};









