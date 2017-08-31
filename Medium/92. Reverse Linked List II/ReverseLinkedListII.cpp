#include <iostream>
#include <utility>
using namespace std;

/* Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.    ***************/

 struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr){}
 }

 class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(!head) { return head; }
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy;
      int i = 1;
      while(prev->next && i < m){
        prev = prev->next;
        i++;
      }
      if(i < m) { return head;} // list.length < int m
      // start = cur, now we reverse nodes until to the nth node
      ListNode* cur = prev->next;
      while(cur->next && i < n){
        ListNode* temp = cur->next;
        cur->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
        i++;
      }
      return dummy->next;
    }
};








