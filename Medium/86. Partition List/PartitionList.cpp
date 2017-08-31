#include <iostream>
using namespace std;

/* Given a linked list and a value x, partition it such that all nodes less than x come before
 * nodes greater than or equal to x.

 * You should preserve the original relative order of the nodes in each of the two partitions.

 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.                              ***************/

 struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr){}
 }

 class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      if(!head || !head->next) { return head; }
      // Task 1: find the first node of which value greater than or equal to x
      // head may be changed, create dummy node
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy;
      ListNode* front; //first node->val >= x
      while(prev->next){
        if(prev->next->val >= x){
          front = prev->next;
          break;
        }
        prev = prev->next;
      }
      cout << "front pointer is " << front->val << endl;
      cout << "prev pointer is " << prev->val << endl;
      if(!prev->next){
          //all nodes are less than int x, just return original list
          return dummy->next;
      }

      // ----> prev ----> front/p_start ----> start ----->
      ListNode *start = front->next;
      ListNode *p_start = front;
      while(start){
        if(start->val < x){
          ListNode* temp = start->next; // preserve next node first
          start->next = front;
          p_start->next = temp;
          prev->next = start;

          prev = prev->next;
          start = temp;
        }
        else{
        p_start = start;
        start = start->next;
        }
      }

      return dummy->next;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *leftTail = leftDummy;
        ListNode *rightTail = rightDummy;

        while (head != NULL) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = head;
            } else {
                rightTail->next = head;
                rightTail = head;
            }
            head = head->next;
        }

        leftTail->next = rightDummy->next;
        rightTail->next = NULL;

        return leftDummy->next;
    }
};










