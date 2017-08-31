//What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

//add starts from tail, we can use stack to store all val;
class Solution{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    if(!l1 || !l2) return l1? l2 : l1;
    stack<int> stc1, stc2;
    ListNode *cur1 = l1, *cur2 = l2;
    //fill the stack;
    while(cur1) {
      stc1.push(cur1->val);
      cur1 = cur1->next;
    }
    while(cur2){
      stc2.push(cur2->val);
      cur2 = cur2->next;
    }

    stack<ListNode*> newstack;
    int carry = 0, sum = 0, value = 0;
    while(!stc1.empty() && !stc2.empty()) {
      sum = stc1.top() + stc2.top() + carry;
      stc1.pop();
      stc2.pop();
      value = sum % 10;
      carry = sum/10;
      ListNode* node = new ListNode(value);
      newstack.push(node);
    }

    while(!stc1.empty()) {
      sum = stc1.top() + carry;
      stc1.pop();
      value = sum % 10;
      carry = sum / 10;
      ListNode* node = new ListNode(value);
      newstack.push(node);
    }

    while(!stc2.empty()) {
      sum = stc2.top() + carry;
      stc2.pop();
      value = sum % 10;
      carry = sum / 10;
      ListNode* node = new ListNode(value);
      newstack.push(node);
    }

    if(carry == 1) {
      newstack.push(new ListNode(1));
    }

    ListNode* head = newstack.top();
    ListNode* cur = head;
    newstack.pop();
    while(!newstack.empty()) {
      cur->next = newstack.top();
      newstack.pop();
      cur = cur->next;
    }
    return head;
  }
};

//modify the code
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1? l2 : l1;
        stack<int> stc1, stc2;
        ListNode *cur1 = l1, *cur2 = l2;
        //fill the stack;
        while(cur1) {
          stc1.push(cur1->val);
          cur1 = cur1->next;
        }
        while(cur2){
          stc2.push(cur2->val);
          cur2 = cur2->next;
        }
        ListNode* res = new ListNode(0);
        int carry = 0;
        while(!stc1.empty() || !stc2.empty()) {
          int sum = 0;
          sum += carry;
          if(!stc1.empty()) { sum += stc1.top(); stc1.pop(); }
          if(!stc2.empty()) { sum += stc2.top(); stc2.pop(); }
          res->val = sum % 10;
          carry = sum / 10;
          ListNode *prev = new ListNode(carry);
          prev->next = res;
          res = prev;
        }
        return res->val == 0? res->next : res;
    }
};
