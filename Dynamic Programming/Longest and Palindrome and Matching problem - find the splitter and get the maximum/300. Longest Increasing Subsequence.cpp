/* O(n^2)
 * Dp: let denote dp[i]: the length of longestIS of [0,..i], which ending with nums[i]
 * base case: dp[0] = 1;
 * dp[i] = 1 + max{dp[k]}, which nums[k] < nums[i] k ranges from[0,..i-1]
 *       = 1, if there is no nums[k] < nums[i] **************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      if(nums.empty()) return 0;

      int n = nums.size();
      vector<int> dp(n, 1);
      dp[0] = 1;

      int res = 1;

      for(int i = 1; i < nums.size(); i++) {
        int temp = 1;
        int MAXI = 0;
        for(int j = 0; j < i; j++) {
          if(nums[j] < nums[i]) {
            MAXI = max(MAXI, dp[j]);
          }
        }
        dp[i] = temp + MAXI;
        res = max(res, dp[i]);
      }
      return res;
    }
};

//Followup: O(nlgn)
/* Assume we have n lists, which size ranges from 1 to n
 *list[0]:
 *list[1]:
 *list[2]:
 *list[3]:
 *...
 *list[n-1]:
 *all these list are increasing sequence, of which index indicates the length of list, respectively
 *to reduce the space, we only store the end number.
 *For example list[5]: means the is length is "6", and the value is the last element of this IS.
 *lgn? why can we achieve lgn? For each incoming element, we can do binary search from all list[i],
 *    to determine which list it can be adder?
 *
 *[key points]1: all lists values are sorted!
 *            2: new incoming element, either update exist "length" list or form a new longer list!
 ******************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      //corner case: empty set
      if(nums.empty()) return 0;

      int n = nums.size();
      //Assumed create n IS with different length = n+1, but only store the last number
      vector<int> list(n, 0);

      list[0] = nums[0];//initialization:length = 1, the list is only nums[0],sure,the last = nums[0]

      /* if new element incoming, do binary search:
       * 1) if nums[i] > all list[],we can create a new longer list by set list[++index] = nums[i]
       * 2) if nums[i] = some list[], ignore
       * 3) if some list[] < nums[i] < some list[], which means find the first list[] bigger than
       *    nums[i], we can update the first list[] bigger one replace by nums[i]
       *
       * combine all the situation above, it seems to find the first list[] which bigger than nums[i]*/
      int index_list = 0;
      for(int i = 1; i < n; i++) {//check each element of nums
        int value = binarySearch(list, nums[i], 0, index_list);
        if(value == -1) {
          list[++index_list] = nums[i];
        }else{
          list[value] = nums[i];
        }
      }

      return index_list + 1;
    }
    //find the first index of list, of which list[index] >= target
    int binarySearch(vector<int>& list, int target, int start, int end) {
      int left = start, right = end;
      if(list[end] < target) { return -1; }//cannot find, increment the list
      while(left < right) {
        int mid = left + (right - right) / 2;
        if(target > list[mid]) {
          left = mid + 1;
        }else{
          right = mid;
        }
      }
      return right;
    }
};












