#include <iostream>


/**
 * starting from the head, swap every two adjacent nodes
 * 1 -> 2 -> 3 -> 4 -> 5  ===>  2 -> 1 -> 4 -> 3 -> 5
 *
 *
 * */
struct ListNode{
  int value;
  ListNode* next;
  ListNode (int x): value(x), next(nullptr){}
};

class Solution{
public:
  ListNode* swapPairs(ListNode* head){
    ListNode* pre_temp = new ListNode(0);
    pre_temp->next = head;
    head = pre_temp;
    while(true){
      if(!pre_temp->next){ break;} // !head
      if(!pre_temp->next->next){ break;} // !head->next
      ListNode* temp1 = pre_temp->next;
      ListNode* temp2 = temp1->next;
      temp1->next = temp2->next;
      temp2->next = temp1;
      pre_temp->next = temp2;
      pre_temp = temp1;
    }
    return head->next;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}