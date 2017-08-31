class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    TreeNode* cur = root;
    while(cur) {
      s_.push(cur);
      cur = cur->left;
    }
  }
  bool hasNext() {
    return !s_.empty();
  }
  int next() {
    int res = 0;
    TreeNode* temp = s_.top();
    res = temp->val;
    s.pop();
    temp = temp->right? temp->right : nullptr;
    while(temp) {
      s_.push(temp);
      temp = temp->left;
    }
    return res;
  }
private:
  stack<TreeNode*> s_;
};