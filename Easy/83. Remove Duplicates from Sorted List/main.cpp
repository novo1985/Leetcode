#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x), next(nullptr){}
};

// given a sorted linked list, delete all duplicates such that each element appears exactly once time
class Solution{
  ListNode* deleteDuplicates(ListNode* head){
    if(!head){ return nullptr;}

    ListNode* curr = head;

    while(!curr->next) {
      if (curr->val == curr->next->val) {
        //delete the curr->next node
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
      }
      else{
        //no deletion, update current pointer
        curr = curr->next;
      }
    }

    return head;
  }
};

int main() {
  Solution test;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}