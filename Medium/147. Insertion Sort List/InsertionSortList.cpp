#include <iostream>
using namespace std;

/* Sort a linked list using insertion sort. */

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if(!head || !head->next) { return head; }
      //insertion sort: backward(if A[j] > A[i] , A[j+1] <- A[j], j -> j-1 )
      //Linkedlist only has *next !?
      ListNode* dummy = new ListNode(0);
      ListNode* cur = dummy;
      //for each iteration, cur need restart from dummy node
      while(head){
        ListNode *temp = head->next;
        cur = dummy;
        while(cur->next && cur->next->val <= head->val){
          cur = cur->next;
        }
        head->next = cur->next; // separate head from original list
        cur->next = head;
        head = temp;
      }
      return dummy->next;
    }
};