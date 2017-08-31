#include <iostream>
using namespace std;

/* Sort a linked list in O(n log n) time using constant space complexity. */

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) { return head;}

      //divide and conque: split one list into two lists.
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* mid = slow->next;
      slow->next = nullptr;//breaking list.
      return merge(sortList(head), sortList(mid));
    }

    ListNode* merge(ListNode* h1, ListNode* h2){
      ListNode* dummy = new ListNode(0); // fixed node pointer
      ListNode* cur = dummy; // cur will be dynamic changed
      //h1 and h2 are sorted list
      while(h1 && h2){
        if(h1->val < h2->val){
          cur->next = h1;
          h1 = h1->next;
        }else{
          cur->next = h2;
          h2 = h2->next;
        }
        cur = cur->next;
      }
      if(h1){cur->next = h1;} // linked the rest nodes
      if(h2){cur->next = h2;}

      return dummy->next;
    }
};




