#include <iostream>
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr){}
};
//merge two sorted linked list.
class Solution{
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(!l1 && l2){ return l2;}
    if(l1 && !l2){ return l1;}
    if(!l1 && !l2){ return nullptr;}

    ListNode* l3 = new ListNode(0);
    ListNode* curr = l3;

    //update two pointers, add the smaller one the new list3
    while(l1 && l2){
      if(l1->val <= l2->val){
        curr->next = l1;
        l1 = l1->next;
      }
      else {
        curr->next = l2;
        l2 = l2->next;
      }
      //the process of constructing new list: 0 -> curr (*p) -> nullptr, keep on constructing while
      // both updated list1 and list2 exist.
      curr = curr->next;
      curr->next = nullptr;
    }
    //After while-loop updating, one of these two lists should run out!
    //case 1: list2 run out
    if(l1){
      curr->next = l1;
    }
    //case 2: list1 run out
    if(l2){
      curr->next = l2;
    }

    //now it is time to return the new list without the first node, which need delete the head node.

    l3 = curr->next;
    delete curr;
    return l3;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}