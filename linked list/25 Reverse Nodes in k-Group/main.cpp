#include <iostream>

struct ListNode{
  int value;
  ListNode* next;
  ListNode(int x):value(x), next(nullptr){}
};

class Solution{
public:
  //recursive function for sublist (begin -> ... -> end) -> next_begin
  ListNode* reverse_list(ListNode* pre_of_head, ListNode* Next_Head){
    ListNode* pre = Next_Head;
    ListNode* HeadToTail = pre_of_head->next;//which will exact previous to next sublist, we need return this node
    ListNode* cur = HeadToTail;
    while(cur && cur != Next_Head){
      ListNode* temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    pre_of_head->next = pre;
    return HeadToTail;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || k == 1){ return head;} // no work needed
    int count = 0;
    ListNode* dummy = new ListNode(0); // to avoid missing the head pointer!
    dummy->next = head; // generate connection with the input list!
    ListNode* prev = dummy; //create a new pointer which points to dummy node, after updata, which always previous to the                        //sublist's head.
    while(head){
      count++;
      if(count == k){
        prev = reverse_list(prev, head->next); // update the position of prev pointer
        count = 0; // reset
        head = prev->next; // reset head pointer
      }else{
        head = head->next;
      }
    }
    return dummy->next;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}