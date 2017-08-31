#include <iostream>
using namespace std;

/* Given a singly linked list, group all odd nodes together followed by the even nodes. Please
 * note here we are talking about the node number and not the value in the nodes.

 * You should try to do it in place. The program should run in O(1) space complexity and
 * O(nodes) time complexity.

 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.     *********************/

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x); next(nullptr){}
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if(!head || !head->next) { return head; }
      ListNode *dummy = new ListNode(0);
      dummy->next = head;

      //ListNode *odd_head = head;
      ListNode *odd_tail = head;
      ListNode *even_head = head->next;
      ListNode *even_tail = head->next;

      //ListNode *prev = even_tail;
      int count = 0;
      while(even_tail->next){
        count++;
        ListNode *temp = even_tail->next;
        if(count % 2 == 1){
          odd_tail->next = temp;
          temp->next = even_head;
          even_tail->next = temp->next;

          odd_tail = odd_tail->next;
        }
        else(count % 2 == 0){
          even_tail = even_tail->next;
        }
      }

      return dummy->next;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};







