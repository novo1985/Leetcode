#include <iostream>

/*Given two linked list to represent two integers, digits are stored in reverse way,
for example,  435 is 5->3->4 , add the two numbers and return the result as reversed linked list*/

// construct node single-linked list structure.
struct ListNode{
  int value;
  ListNode *pnext;
  ListNode();
  ListNode(int i): value(i), pnext(NULL){}
};

class add_two_numbers{
public:
  ListNode* list1;
  ListNode* list2;

  //constructor
  add_two_numbers(ListNode* L1, ListNode* L2): list1(L1), list2(L2){}

  //function
  ListNode* add(ListNode* l1, ListNode* l2){

    ListNode rootNode(0);
    ListNode* cur = &rootNode;
    int overflow = 0;

    while(l1 || l2) {
      int value1 = (l1 ? l1->value : 0);
      int value2 = (l2 ? l2->value : 0);
      int sum = value1 + value2 + overflow;
      overflow = sum / 10;
      sum = sum % 10;
      ListNode *p_new = new ListNode(sum);
      cur->pnext = p_new;
      cur = cur->pnext;
      if (l1) { l1 = l1->pnext; }
      if (l2) { l2 = l2->pnext; }

      if (overflow > 0) {
        ListNode *p_nnew = new ListNode(overflow);
        cur->pnext = p_nnew;
      }
    }
      return rootNode.pnext;
  }
};
