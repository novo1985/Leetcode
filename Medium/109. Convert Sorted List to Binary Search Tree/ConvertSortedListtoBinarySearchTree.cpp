#include <iostream>
#include <utility>
using namespace std;

/* Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.    ***************/

 struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr){}
 }

 struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 }

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if(!head){ return nullptr;}
      TreeNode* root = newTreeNode_midListNode(head);
    //   ListNode* left = L_list;
    //   ListNode* right = R_list;

    //   root->left = sortedListToBST(left);
    //   root->right = sortedListToBST(right);
      return root;
    }

    TreeNode* newTreeNode_midListNode(ListNode* h1){
      if(!h1){
        return nullptr;
      } // empty list or only one node
      if(!h1->next){
        TreeNode* newnode = new TreeNode(h1->val);
        newnode -> left = nullptr;
        newnode -> right = nullptr;
        return newnode;
      }


      ListNode *fast = h1, *slow = h1, *prev = h1;
      while(fast->next && fast->next->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      //two nodes case: 1-->2-->null
      /* slow == 1  prev == 1  slow->next == 2
       * */
      ListNode *L_list, *R_list;

      TreeNode* mid = new TreeNode(slow->val);
      R_list = slow->next;
      slow->next = nullptr;
      if(slow == h1){
        L_list = nullptr;
      }else{
        prev->next = nullptr;
        L_list = h1;
      } // --------- [] ----------

      mid -> left = newTreeNode_midListNode(L_list);
      mid -> right = newTreeNode_midListNode(R_list);
      return mid;
    }
// private:
//   ListNode *L_list, *R_list;
  //pair<ListNode*, ListNode*> newlists;
};












