#include <iostream>

/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 */
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
  ListNode* detectCycle(ListNode* head){
    // fast-slow pointer to check cycle
    if(!head || !head->next){ return nullptr;}
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next){
      fast = fast->next->next;
      slow = slow->next;
      if(fast == slow) { // there is a cycle  X == Z
        fast = head; // put the fast point to head position
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}