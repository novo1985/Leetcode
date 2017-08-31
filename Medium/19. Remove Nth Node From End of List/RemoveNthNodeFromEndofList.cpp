#include <iostream>
using namespace std;

/* Given a linked list, remove the nth node from the end of list and return its head.
 * Given n will always be valid. Try to do this in one pass. ****************/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr){}
};


// To find the position, using slow-fast pointers. the distance[slow, fast] = n-1;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(!head) { return head; }
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* slow = dummy;
      ListNode* fast = dummy;
      int i = 0;
      //let fast pointer move n-1 steps first!
      while(fast->next && i < n-1){
        fast = fast->next;
        i++;
      }
      //slow/fast move together until fast->next == null
      while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next;
      }
      // remove target == slow->next
      ListNode* target = slow->next;
      ListNode* temp = target->next;
      slow->next = temp->next;
      delete target;
      return dummy->next;
    }
};
