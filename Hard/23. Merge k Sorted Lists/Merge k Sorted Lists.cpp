#include <bits/stdc++.h>
using namespace std;

/* Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()) { return nullptr; }
      if(lists.size() == 1) { return lists[0];}
      while(lists.size() >= 2){
        ListNode* l1 = lists[0];
        ListNode* l2 = lists[1];
        ListNode* node = merge2List(l1, l2);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
        lists.push_back(node);
      }
      return lists[0];
    }

    ListNode* merge2List(ListNode* l1, ListNode* l2){
      ListNode* dummy = new ListNode(-1);
      ListNode *cur = dummy;
      while(l1 || l2) {
        int val = min((l1? l1->val : INT_MIN), (l2? l2->val : INT_MIN));
        cur->next = new ListNode(val);
        if(l1 && l2 && l1->val == val && l2->val == val){
          l1 = l1->next;
        }
        if(l1 && l1->val == val){ l1 = l1->next; }

        else if (l2 && l2->val == val){
          l2 = l2->next;
        }
        cur = cur->next;
      }
        return dummy->next;
    }

};

//priority queue
class Solution {
public:
    struct compNode {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val>q->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
        ListNode *dummy = new ListNode(0), *tail = dummy;

        for(int i=0; i<lists.size(); i++)
            if(lists[i]) pq.push(lists[i]);

        while(!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next) pq.push(tail->next);
        }

        return dummy->next;
    }
};

//merge two list, binary merge
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()) { return nullptr; }
      if(lists.size() == 1) { return lists[0]; }
      int begin = 0, end = lists.size()-1;
      while(end > 0){
        lists[0] = merge2List(lists[0], lists[end]);
        end--;
      }
      return lists[0];
    }
    ListNode* merge2List(ListNode* l1, ListNode* l2){
      ListNode* dummy = new ListNode(-1);
      ListNode* cur = dummy;
      while(l1 && l2){
        if(l1->val <= l2->val){
          /*ListNode* temp = l1->next;
          l1->next = nullptr;
          cur->next = l1;
          cur = cur->next;
          l1 = temp;*/
          cur->next = l1;
          l1 = l1->next;
        }else{
          /*ListNode* temp = l2->next;
          l2->next = nullptr;
          cur->next = l2;
          cur = cur->next;
          l2 = temp;*/
          cur->next = l2;
          l2 = l2->next;
        }
        cur = cur->next;
      }
      cur->next = l1? l1 : l2;
      return dummy->next;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        int end = lists.size()-1;
        while(end>0) {
            int begin = 0;
            while(begin<end) {
                lists[begin] = merge2Lists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }

    ListNode* merge2Lists(ListNode *h1, ListNode *h2) {
        ListNode *dummy = new ListNode(0), *tail = dummy;
        while(h1 && h2) {
            if(h1->val<=h2->val) {
                tail->next = h1;
                h1 = h1->next;
            }
            else {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        tail->next = h1 ? h1 : h2;
        return dummy->next;
    }
};










