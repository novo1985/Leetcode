#include <iostream>
using namespace std;

/* You are given two non-empty linked lists representing two non-negative integers. The most
 * significant digit comes first and each of their nodes contain a single digit. Add the two
 * numbers and return it as a linked list.

 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * For example,
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7                    *********************/

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x); next(nullptr){}
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1 && !l2) {return nullptr;}
      if(!l1 || !l2) {return l1 ? l1 : l2;}

      ListNode* rev_l1 = reverseList(l1);
      ListNode* rev_l2 = reverseList(l2);

      ListNode* dummy = new ListNode(0);
      ListNode* cur = dummy;
      int carry = 0;
      while(rev_l1 || rev_l2){
        int sum = 0;
        if(rev_l1) { sum += rev_l1->val; rev_l1 = rev_l1->next;}
        if(rev_l2) { sum += rev_l2->val; rev_l2 = rev_l2->next;}
        sum += carry;
        ListNode* newnode = new ListNode(sum % 10);
        carry = sum / 10;
        cur->next = newnode;
        cur = cur->next;
      }
      if(carry == 1){
        ListNode *newnode = new ListNode(1);
        cur->next = newnode;
      }

      return reverseList(dummy->next);
    }


    ListNode* reverseList(ListNode* head){
      if(!head || !head->next) { return head; }
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      //ListNode* prev = dummy;
      while(head->next){
        ListNode * temp = head->next;
        head->next = temp->next;
        temp->next = dummy->next;
        dummy->next = temp;
      }
      return dummy->next;
    }
};




/* using stack, list do not need reverse */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {sum += s1.top(); s1.pop();}
            if (!s2.empty()) {sum += s2.top(); s2.pop();}
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};











