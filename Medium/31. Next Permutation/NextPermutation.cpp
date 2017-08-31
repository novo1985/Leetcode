#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
//#include <unordered_map>
using namespace std;

/* Implement next permutation, which rearranges numbers into the lexicographically next greater
 * permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order
   (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.

 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in
 * the right-hand column.
   1,2,3 → 1,3,2
   3,2,1 → 1,2,3
   1,1,5 → 1,5,1     *****************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      if(nums.size() < 2) { return; }
      int index;
      int i = nums.size()-1;
      while(i>=1){
        if(nums[i] <= nums[i-1]){
          i--;
          if(i==0){
            sort(nums.begin(), nums.end());
            return;
          }
        }
      }
      index = i-1;
      //swap(some(nums[i .. n-1]), nums[i-1]);
      //for sure: subarray[i,..n-1] is descent array, find first element bigger than  nums[i-1]
      while( i < nums.size() && nums[i] > nums[index]){
        i++;
      }
      i--;
      swap(nums[index], nums[i]);

      // we need sort subarray[index+1 .. n-1],
      sort(nums.begin()+index+1, nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2) return;
        int n = num.size(), j = n-2;
        while(j>=0 && num[j]>=num[j+1]) j--;

        if(j<0) {
            sort(num.begin(),num.end());
            return;
        }

        int i=j+1;
        while(i<n && num[i]>num[j]) i++;
        i--;

        swap(num[i],num[j]);
        sort(num.begin()+j+1, num.end());
    }
};





