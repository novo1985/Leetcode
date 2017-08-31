#include <bits/stdc++.h>
using namespace std;

/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
two nodes v and w as the lowest node in T that has both v and w as descendants
(where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of
nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition. ***/

//solution1: recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root || p == root || q == root) { return root; }
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      TreeNode* right = lowestCommonAncestor(root->right, p, q);
      if (left && right) return root;
      return left ? left : right;
    }
};

//solution2: iteration
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> left_stack;
        vector<TreeNode*> right_stack;
        TreeNode* node = root;
        TreeNode* lca = NULL;
        while(node)
        {
            if(node == p || node == q)
                if(lca == NULL)
                    lca = node;
                else
                    return lca;
            left_stack.push_back(node);
            node = node->left;
        }
        while(left_stack.size() > 0)
        {
            node = left_stack.back();
            if(node->right == NULL)
            {
                left_stack.pop_back();
                if(node->left != NULL && node->left == lca)
                    lca = node;
                continue;
            }
            if(right_stack.size() > 0 && node == right_stack.back())
            {
                left_stack.pop_back();
                right_stack.pop_back();
                if(lca != NULL && (node->left == lca || node->right == lca))
                    lca = node;
                continue;
            }
            if(lca != NULL && (node->left == lca || node->right == lca))
                lca = node;
            right_stack.push_back(node);
            node = node->right;
            while(node)
            {
                if(node == p || node == q)
                    if(lca == NULL)
                        lca = node;
                    else
                        return lca;
                left_stack.push_back(node);
                node = node->left;
            }
        }
        return NULL;
    }
};
















