/* Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   /
  3   1 5   */

/*solution: we read the string by pre-order traversal*/

/* preorder - iteration:
 * string preorder(TreeNode* root){
 *    string res;
 *    if(!root) { return res; }
 *    stack<TreeNode*> s;
 *    s.push(root);
 *    while(!s.empty()){
 *      TreeNode* cur = s.top();
 *      string += to_string(cur->val);
 *      s.pop();
 *      if(cur->right) { s.push(cur->right); }
 *      if(cur->left) { s.push(cur->left); }
 *    }
 *    return string;
 *      *******/
class Solution{
public:
  TreeNode* str2tree(string s){
    if(s.empty()) { return nullptr; }
    //find the first '(';
    int found = s.find('(');
    int val = (found == -1)? stoi(s) : stoi(s.substr(0, found));
    TreeNode *root = new TreeNode(val);
    int start = found;
    int cound = 0;
    for(int i = start; i < s.size(); i++){
      if(s[i] == '(') count++;
      else if(s[i] == ')') count--;
      if(count == 0 && start ==found){//left substree
        root->left = str2tree(s.substr(start+1, i-start-1));
        start = i + 1//begin of right subtree
      }
      else if(count == 0){
        root->right = str2tree(s.subtree(start+1, i-start-1));
      }
    }
    return root;
  }
};