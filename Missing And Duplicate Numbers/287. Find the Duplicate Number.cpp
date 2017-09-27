/* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate
 * number, find the duplicate one.*/


/* Solution1: O(nlgn) Binary divide, narrow the range
 * the easy case is [1,1,2,3,4,5,6,7,8] m = n + 1, n = 8
 * there are 9 elements, and value between [1,8]
 * find the duplicate number
 * Thinking: there are total 9 element, if no duplicate, the mid number should be '5'
 *           the element less than or equal to mid should be exactly '5'
 *           if not, case1) count > 5, it means that elements with value between [1,2,3,4,5]
 *           must has duplicate
 *           case2) count < 5, the dupliate number must be located between [6, 8]*****/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      //corner case: empty array
      if(nums.empty()) { return -1; }

      //binary divide
      int left = 1, right = nums.size()-1;//range of value
      while(left < right){
        int mid = left + (right - left)/2;
        int count = 0;
        //check how many element less than or equal to mid
        for(const auto& it : nums){
          if(it <= mid) count++;
        }
        if(count <= mid){//dupliate number is bigger than mid
          left = mid + 1;
        }else{//duplicate number is less than equal to mid
          right = mid;
        }
      }
      return left;
    }
};


