#include <iostream>
using namespace std;

/* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only
 * distinct numbers from the original list.

 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.                    *********************/

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x); next(nullptr){}
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head || !head->next) { return head; }
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy;
      //ListNod *prev = head, *cur = prev->next;
      while(prev->next){
        ListNode* temp = prev->next;
        while( temp->next && temp->val == tem->next->val){
          temp = temp->next;
        }
        if(temp != prev->next) { // exist duplicates: prev-->1-->1-->1-->2
                                 //                                  |
          prev->next = temp->next;
        }
        else{ //
          prev = prev->next;
        }
      }
      return dummy->next;
    }
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *pre = start;
        while (pre->next) {
            ListNode *cur = pre->next;
            while (cur->next && cur->next->val == cur->val) cur = cur->next;
            if (cur != pre->next) pre->next = cur->next;
            else pre = pre->next;
        }
        return start->next;
    }
};






