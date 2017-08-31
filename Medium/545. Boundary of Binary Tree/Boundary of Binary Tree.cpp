/* the whole task can be divided into three parts:
 * 1) print the left boundary;(up-bottom)
 * 2) print leaves nodes;(left-right)
 * 3) print the right boundary(bottom-up)*/

//solution 1:  stacks
class Solution{
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root){
    vector<int> res;
    if(!root) { return res; }
    TreeNode *l = root->left, *r= root->right, *cur = root;
    //add root value;
    res.push_back(root->val);
    //task1: add left boundary but not leaf node
    while(l && (l->left || l->right)){//not leaf node
      res.push_back(l->val);
      l = (l->left)? l->left : l->right;
    }//done add all the leftboundary to res;

    //task2: add leaves node
    stack<TreeNode*> st;
    while(cur || !st.empty()){
      if(cur) {
        st.push(cur);
        if(!cur->left && !cur->right) { res.push_back(cur->val); }
        cur = cur->left;
      }
      else{
        cur = s.top();
        s.pop();
        cur = cur->right;
      }
    }//done, all leave nodes added

    //task3: add right boundary;
    vector<int> RB;
    while(r && (r->left || r->right)){
      RB.push_back(r->val);
      r = (r->right)? r->right : r->left;
    }
    reverse(RB.begin(),RB.end());
    res.insert(res.end(), RB.begin(), RB.end());
    return res;
  }
};

//solution2: recursion
class Solution{
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root){
    vector<int> res;
    if(!root) { return res; }
    if(root->left || root->right) { res.push_back(root->val); }
    leftboundary(root->left, res);
    leafnode(root, res);
    rightboundary(root->right, res);
    return res;
  }

  void leftboundary(TreeNode* node, vector<int>& res){
    if(!node) { return; }
    if(node->left || node->right){//not leaf node!
      //add value first
      res.push_back(node->val);
      node = node->left? node->left : node->right;
      leftboundary(node, res);
    }else{
      return;//leaf node
    }
  }

  void leafnode(TreeNode* node, vector<int>& res){
    if(!node) { return; }
    if(!node->left && !node->right) { res.push_back(node->val); }
    leafnode(node->left, res);
    leafnode(node->right, res);
  }

  void rightboundary(TreeNode* node, vector<int>& res){
    if(!node) { return; }
    if(node->left || node->right){//not leaf node
      //add the value end of recursion
      if(node->right){ rightboundary(node->right, res); }
      else{ rightboundary(node->left, res); }

      res.push_back(node->val)
    }
  }
};







