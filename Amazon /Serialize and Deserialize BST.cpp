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
        return deserilization(in);
    }
private:
    void serilization(TreeNode* root, ostringstream& out){
        if(root){
            out << root->val << ' ';
            serilization(root->left, out);
            serilization(root->right, out);
        }else{
            out << "# ";
        }
    }
    TreeNode* deserilization(istringstream& in){
        string val;
        in >> val;
        if(val == "#") { return nullptr;}

        TreeNode* node = new TreeNode(stoi(val));

        node->left = deserilization(in);
        node->right = deserilization(in);
        return node;
    }
};
