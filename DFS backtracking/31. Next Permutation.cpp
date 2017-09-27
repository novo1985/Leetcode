/* The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the
right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/
/*1 Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists,
    the permutation is sorted in descending order, just reverse it to ascending order and we are done.
    For example, the next permutation of [3, 2, 1] is [1, 2, 3].
 *2 Find the largest index l greater than k such that nums[k] < nums[l].
 *3 Swap the value of nums[k] with that of nums[l].
 *4 Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find largest index k, nums[k] < nums[k+1], if not exist, descending array, just reverse
        int k = -1, n = nums.size();

        for(int i = n - 2; i >= 0; i--) {//find largest index k
          if(nums[i] < nums[i+1]) {
            k = i;
            break;
          }
        }

        //if not find such index, k == -1
        if(k == -1) {
          reverse(nums.begin(), nums.end());
          return;
        }

        //if find such k, find largest index l which greater than k, such that nums[l] > nums[k]
        int l = -1;
        for(int i = n - 1; i  >= 0; i--) {
          if(nums[i] > nums[k]) {
            l = i;
            break;
          }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};









