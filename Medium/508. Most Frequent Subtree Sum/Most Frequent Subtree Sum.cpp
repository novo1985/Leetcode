#include <bits/stdc++.h>
using namespace std;

/* Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree
 * sum of a node is defined as the sum of all the node values formed by the subtree rooted at
 * that node (including the node itself). So what is the most frequent subtree sum value? If
 * there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
------------------------------------------------
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.  **************************/

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
      //unordered_map<TreeNode*, int> m;
      unordered_map<int, int> freq;
      vector<int> res;
      if(!root) { return res; }
      int max_freq = 0;
      dfs(root, max_freq, freq);
      for(auto a : freq){
        if(a.second == max_freq){
          res.push_back(a.first);
        }
      }
      return res;
    }
    int dfs(TreeNode *root, int& max_freq, unordered_map<int, int>& freq){
        int sum = 0;
        sum += root->val;
        if(root->left){
          sum += dfs(root->left, max_freq, freq);
        }
        if(root->right){
          sum += dfs(root->right, max_freq, freq);
        }
      freq[sum]++;
      max_freq = freq[sum] > max_freq ? freq[sum] : max_freq;
      return sum;
    }
};




class Solution {
public:
    int postOrder(TreeNode* root, unordered_map<int, int>& counts,int& maxC) {
        int sum = root->val;
        if (root->left)
            sum += postOrder(root->left, counts, maxC);
        if (root->right)
            sum += postOrder(root->right, counts, maxC);
        counts[sum]++;
        maxC = maxC < counts[sum] ? counts[sum] : maxC;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        unordered_map<int, int> counts;
        int maxC = INT_MIN;
        postOrder(root, counts,maxC);
        for (auto p : counts) {
            if (p.second == maxC)
                ans.push_back(p.first);
        }
        return ans;
    }
};







