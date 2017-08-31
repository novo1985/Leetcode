/* A:          a1 → a2
                       ↘
                          c1 → c2 → c3
                       ↗
   B:     b1 → b2 → b3
*/
/*solution1: check intersection by tail node, if tailA == tailB, two list converged together
 *           let longer list go |len1 - len2| steps first */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(!headA || !headB) { return nullptr; }
      ListNode* cur_A = headA, *cur_B = headB;
      int lenA = 1, lenB= 1;
      while(cur_A->next) { lenA++; cur_A = cur_A->next; }
      while(cur_B->next) { lenB++; cur_B = cur_B->next; }
      if(cur_A != cur_B) { return nullptr; }
      cur_A = headA;
      cur_B = headB;
      if(lenA > lenB) {
        int k = lenA - lenB;
        while(k) {
          cur_A = cur_A->next;
          k--;
        }

      }else if(lenA < lenB) {
        int k = lenB - lenA;
        while(k) {
          cur_B = cur_B->next;
          k--;
        }
      }
      while(cur_A && cur_B) {
          if(cur_A != cur_B) {
              cur_A = cur_A->next;
              cur_B = cur_B->next;
          }
          else {
            return cur_A;
          }
      }
    }
};












