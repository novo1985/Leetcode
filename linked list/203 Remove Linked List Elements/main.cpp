#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// Remove all elements from a linked list of integers that have value val.

class Solution{
public:
  ListNode* removeElements(ListNode* head, int val){
    if(!head){return head;}
    ListNode* cur = head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    while(cur){
      if(cur->val == val){
        ListNode* temp = cur->next;
        prev->next = temp;
        cur = temp->next;
        prev = cur;
      }
      else{
        cur = cur->next;
      }

    return dummy->next;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}