#include <iostream>
using namespace std;

/* Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5                              *******/

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      if(!head) {return nullptr;}
      //dummy node "prev"
      ListNode* prev = new ListNode(0);
      prev->next = head;

      head = prev;

      ListNode* temp;
      while(prev->next){
        if(prev->next->val == val){
          temp = prev->next->next;
          prev->next = temp;
        }
        else{
          prev = prev->next;
        }
      }
      return head->next;
    }
};