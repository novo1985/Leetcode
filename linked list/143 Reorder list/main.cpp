#include <iostream>
struct ListNode{
  int value;
  ListNode* next;
  ListNode(int x): value(x), next(nullptr){}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        /** it can be divided into three parts: (1)find the median node and break into two list;
         *                                      (2)reverse the second half list;
         *                                      (3)merge this two lists; */
         ListNode* fast = head;
         ListNode* slow = head;
         ListNode* second_head = head;
         if(!head){ return;}
         while(fast != nullptr && fast->next != nullptr){
             fast = fast->next->next;
             slow = slow->next;
         }
         second_head = slow->next;
         slow->next = nullptr; // break the linkage and form two list (head---->slow) and (second_head------>null)

         //step2: reverse the second list
         ListNode* prev = nullptr;
         ListNode* cur = second_head;
         while(cur){
             ListNode* temp = cur->next;
             cur->next = prev;
             prev = cur;
             cur = temp;
         }
         second_head = prev; // update the position of second_head pointer

         //merge this two list, while loop, the terminate condition should second list is null;
         while(second_head){
             // we need record the linkages of these two list first!
             ListNode* temp_1 = head->next;
             ListNode* temp_2 = second_head->next;
             head->next = second_head;
             second_head->next = temp_1;
             head = temp_1;
             second_head = temp_2;
         }






    }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}