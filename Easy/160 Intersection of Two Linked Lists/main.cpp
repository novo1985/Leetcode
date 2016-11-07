#include <iostream>

/** Definition for singly-linked list.**/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/** find the node at which the intersection of two singly linked lists begins. */
class Solution {
public:
  Solution(){};
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr){ return NULL;}
    int lengthA = 1;
    int lengthB = 1;
    ListNode *tailA = headA;
    ListNode *tailB = headB;
    while(tailA->next){
      tailA = tailA->next;
      lengthA++;
    }
    while(tailB->next){
      tailB = tailB->next;
      lengthB++;
    }
    if(tailA != tailB){ return NULL;}

    if(lengthA > lengthB){
      for(int i = 0; i < lengthA - lengthB; i++){
        headA = headA->next;
      }
    }
    else{
      for(int i = 0; i < lengthB - lengthA; i++){
        headB = headB->next;
      }
    }
    while(headA != headB){
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};

int main() {

}