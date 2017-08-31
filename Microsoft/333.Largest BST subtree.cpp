struct NodeInfo{
  bool valid = false;
  int maxvalue = INT_MIN;
  int minValue = INT_MAX;
  int size = 0;
};
class Solution{
public:
  int largestBSTSubtree(TreeNode* root) {
    NodeInfo Info = helper(root);
    return Info.size;
  }
  NodeInfo helper(TreeNode* root) {
    //base case
    if(!root) {
      NodeInfo info;
      info.valid = true;
      info.maxvalue = INT_MIN;
      info.minValue = INT_MAX;
      info.size = 0;
      return info;
    }
    //if root is not null
    NodeInfo left = helper(root->left);
    NodeInfo right = helper(root->right);
    NodeInfo rootinfo;
    //suppose left and right is finished, update rootinfo
    rootinfo.valid = (left.valid && right.valid) && (left.maxvalue < root->val) &&
                                                                 (right.minValue > root->val);
    if(rootinfo.valid) {//update
      rootinfo.maxvalue = max(right.maxvalue, root->val); //because maxvalue initalized to INT_MIN
      rootinfo.minValue = min(left.minValue, root->val);//
      rootinfo.size = 1 + right.size + left.size;
    }else {//rootinfo is not valid
      rootinfo.size = max(left.size, right.size);
    }
    return rootinfo;
  }
};

//solution2: using reference & pointer
struct NodeInfo{
  bool valid;
  int maxvalue;
  int minValue;
  int size;
  NodeInfo(){
      valid = false;
      maxvalue = INT_MIN;
      minvalue = INT_MAX;
      size = 0;
  };
};
class Solution{
public:
  int largestBSTSubtree(TreeNode* root) {
    if(!root) { return 0; }
    NodeInfo* info = helper(root);
    return info->size;
  }
  NodeInfo* helper(TreeNode* root) {
    if(!root) {
      NodeInfo* info = new NodeInfo();
      info->valid = true;
      info->maxvalue = INT_MIN;
      info->minvalue = INT_MAX;
      info->size = 0;
      return info;
    }
    //root is not null
    NodeInfo* left = helper(root->left);
    NodeInfo* right = helper(root->right);
    NodeInfo* rootinfo = new NodeInfo();
    rootinfo->valid = (left->valid && right->valid) && (left->maxvalue < root->val
      && right->minvalue > root->val);
    if(rootinfo->valid) {//if the subtree including root is BST, we need update information
      rootinfo->maxvalue = max(right->maxvalue, root->val);
      rootinfo->minvalue = min(left->minvalue, root->val);
      rootinfo->size = 1 + left->size + right->size;
    }else {//subtree including root is not a BST, SIZE depends on its leftsubtree or rightsubtree
      rootinfo->size = max(left->size, right->size);
    }
    return rootinfo;
  }
};

















