#include <iostream>
using namespace std;

/**  Given a linked list, to determine if it has a cycle
 *   (without using extra space)
 *   -----------------
 *   One pointer is slow (1 step a time)
 *   One pointer is fast (2 steps a time)
 *   If there is a cycle, the two pointers will eventually meet (equal).
 *   -----------------
 */
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x),next(nullptr){}
};

class Solution{
public:
  bool hasCycle(ListNode* head){
    if(!head){return false;}
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast){ return true;}
    }
    return false;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}