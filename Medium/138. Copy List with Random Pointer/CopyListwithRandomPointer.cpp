#include <iostream>
#include <unordered_map>
using namespace std;

/* A linked list is given such that each node contains an additional random pointer which could
 * point to any node in the list or null.
 * Return a deep copy of the list. ******************/

struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL),random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if(!head) { return head; }
      RandomListNode *dummy = new RandomListNode(0);
      RandomListNode *cur = dummy;
      RandomListNode *temp = head; // do not lose head position.
      unordered_map<RandomListNode*, RandomListNode*> map;
      while(temp){
        //deep copy, create all new nodes firstly!
        RandomListNode *newnode = new RandomListNode(temp->label);
        cur->next = newnode;
        cur = cur->next;
        map[temp] = newnode; // mapping oldnode with newnode!!!
        temp = temp->next;
      }
      //Task2: copy all random pointers, connections
      temp = head; //reset temp position
      while(temp){
        if(temp->random){
          //what is the random pointer for the coordinated newnode?? it should point to some newnode
          map[temp]->random = map[temp->random]; //bingo!
        }
        temp = temp->next;
      }
      return dummy->next;
    }
};