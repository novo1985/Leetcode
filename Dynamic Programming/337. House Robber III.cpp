/* There is only one entrance to this area, called the "root." Besides the root, each house has
 * one and only one parent house. After a tour, the smart thief realized that "all houses in this
 * place forms a binary tree". It will automatically contact the police if two directly-linked
 * houses were broken into on the same night.*/


/* solution1: recursion function "f": from current node, the max money you can rob
 * it should be two case: 1) rob current node; 2) donot rob current node
 * Therefore, the f(node) = max(node->val + f(node->left->left) + f(node->left-right)
  + f(node->right->left) + f(node->right->right), f(node->left) + f(node->right))
 *Time Complexity: O(n^2logn) */
class Solution {
public:
    int rob(TreeNode* root) {//f = rob function, it return max money robbed from root!
      //corner case:
        if(!root) { return 0; }

      //value1: rob current node;
      int val = root->val;
      if(root->left) {
        val += rob(root->left->left) + rob(root->left->right);
      }
      if(root->right) {
        val += rob(root->right->left) + rob(root->right->right);
      }
      //value2: rob(root->left) + rob(root->right);
      return max(val, rob(root->left) + rob(root->right));
    }
};

/* solution2: DP store intermediate res: res[0]/not including, res[1]/including*/
class Solution{
public:
  int rob(TreeNode* root){
    vector<int> res = robber(root);
    return max(res[0], res[1]);
  }
  vector<int> robber(TreeNode* node) {
    vector<int> res(2, 0);
    if(!node) { return res; }
    vector<int> left = robber(node->left);
    vector<int> right = robber(node->right);

    res[0] = max(left[0], left[1]) + max(right[0], right[1]);//not including current node;
    res[1] = node->val + left[0] + right[0];//including current node;
    return res;
  }
};

