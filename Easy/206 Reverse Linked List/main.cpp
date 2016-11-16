#include <iostream>

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
         /**prev = NULL;
          * temp = head->next;
          * head->next = prev;
          * prev = head;
          * head = temp;
          * exchange two nodes;
          */
    ListNode* temp;
    ListNode* prev = nullptr;
    while(!head){
      temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }
    // until temp = NULL, new head = NULL, exit while loop, but head should be prev pointer.
    head = prev;
    return head;
  }
};

int main() {
  Solution test;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}