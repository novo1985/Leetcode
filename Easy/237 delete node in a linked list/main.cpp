#include <iostream>
using namespace std;
struct ListNode{
  int val;
  ListNode* _pnext;
  //constructor1 no argument.
  ListNode(void):_pnext(nullptr){}
  //constructor2, with a given value
  ListNode(int x): val(x), _pnext(nullptr){}
  //constructor3, with given value and linked list
  ListNode(int x, ListNode* next): val(x), _pnext(next){}
};

class LinkedList{
public:
  ListNode* _phead;
  ListNode* _ptail;
  //constructor1
  LinkedList(ListNode* node){}
  //constructor2
  LinkedList(int value){}
  //de-constructor
  ~LinkedList(void){};

  //function1: remove any node
  void remove(ListNode* node);
};

void LinkedList::remove(ListNode *node) {
  //we only have pnext pointer, we can update this current node, its value equals to its next node, its pnext
  //points to next node's next ( so we can just delete current node's next node.
  ListNode* temp = node->_pnext;
  node->val = temp->val;
  node->_pnext = temp->_pnext;
  delete temp;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}