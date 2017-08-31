class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(!head || !head->next) {
        return head;
      }
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy, *cur = head;
      while(cur && cur->next) {
        ListNode* temp = cur->next->next;
        cur->next->next = prev->next;
        prev->next = cur->next;
        cur->next = temp;
        prev = cur;
        cur = temp;
      }
      return dummy->next;
    }
};

//recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(!head || !head->next) {
        return head;
      }
      ListNode* second = head->next;
      ListNode* third = second->next;
      second->next = head;
      head->next = swapPairs(third);
      return second;
    }
};





