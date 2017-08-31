


class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = to_string(t->val);

        if (t->left) {
            s += "(" + tree2str(t->left) + ")";
        }
        else if (t->right) {
            s += "()";
        }

        if (t->right) {
            s += "(" + tree2str(t->right) + ")";
        }
        return s;
    }
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        string res;
        preorder(t, res);
        return res;
    }
    void preorder(TreeNode* t, string& str){
        if(!t) { return; }
        str +=  to_string(t->val);
        if(t->left) {
            str += "(";
            preorder(t->left, str);
            str += ")";
        }else if( !t->left && t->right){
            str += "()";
        }
        if(t->right){
            str += "(";
            preorder(t->right,str);
            str += ")";
        }
    }
};