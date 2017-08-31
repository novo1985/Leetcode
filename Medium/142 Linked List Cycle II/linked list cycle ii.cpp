class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       //Floyd algorithm
        if(!head || !head->next) { return nullptr; }
        ListNode* fast = head;
        ListNode* slow = head;
        bool cycle = false;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                cycle = true;
                break;
            }
        }
        if(cycle) {
            fast = head;
            while(fast && slow) {
                if(fast == slow) {
                    return fast;
                }else {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }else{
            return nullptr;
        }
    }
};