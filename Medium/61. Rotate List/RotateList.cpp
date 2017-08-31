#include <iostream>
using namespace std;

/* Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.                         *****************/

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head) { return head; }
      // k % list.length() == 0, no change
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      int len = 1;
      ListNode* p = head;
      while(p->next){
        p = p->next;
        len++;
      }

      if( k % len == 0) { return dummy->next; }

      int m = k % len;
      ListNode* prev = head;
      int i = 1;
      while(prev->next && i < len-m){
        prev = prev->next;
        i++;
      }
      //now prev->next == new head
      ListNode* newhead = prev->next;
      ListNode* oldtail = newhead;
      while(oldtail->next){
        oldtail = oldtail->next;
      }
      dummy->next = newhead;
      oldtail->next = head;
      prev->next = nullptr;
      return dummy->next;
    }
};












