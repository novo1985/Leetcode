#include <bits/stdc++.h>
using namespace std;

/* Find the kth largest element in an unsorted array. Note that it is the kth largest element in the
 * sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.*/

/* solution1 : sort, O(nlgn) */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty() || nums.size() < k) { return -1; }
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};


/* solution2: quicksort, average Time O(n), */
class Solution{
public:
  int findKthLargest(vector<int>& nums, int k){
    return quickselect(nums, 0, nums.size()-1, k);
  }

  int quickselect(vector<int>& nums, int start, int end, int k){
    if(start <= end){
      int index = partition(nums, start, end);
      //the numbers of element in the left side including pivot = index - start + 1;
      int m = index - start + 1;
      if(m == k) { return nums[index]; }
      else if(m > k){
        return quickselect(nums, start, index-1, k);
      }
      else{
        return quickselect(nums, index+1, end, k-m);
      }
    }
  }
  //partion, return i+1, all element < pivot in the left, all element > pivot in the right
  int partition(vector<int>& nums, int start, int end){
    int pivot = nums[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j++){
      if(nums[j] > pivot){
        i = i + 1;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i+1], pivot);
    return i+1;
  }
};

int findKthLargest(vector<int>& nums, int k) {
    const int size_n = nums.size();
    int left = 0, right = size_n;
    while (left < right) {
        int i = left, j = right - 1, povit = nums[left];
        while(i <= j) {
            while (i <= j && nums[i] >= povit) i++;
            while (i <= j && nums[j] < povit) j--;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        if (j == k - 1) return nums[j];
        if (j < k - 1) left = j + 1;
        else right = j;
    }
}

class Solution {
public:
  int partition(vector<int>& nums, int i, int j)
  {
    if (i == j) return i;

    int pivot = nums[i];
    std::swap(nums[i], nums[j]);

    int i0 = i;
    for(int k = i; k < j; k ++)
    {
      if(nums[k] <= pivot)
      {
        std::swap(nums[k], nums[i0 ++]);
      }
    }
    std::swap(nums[i0], nums[j]);
    return i0;
  }
    int findKthLargest(vector<int>& nums, int k)
  {
    size_t len = nums.size();
    int pi = 0;
    int tgt = len - k;

    int a = 0, b = len - 1;
    while((pi = partition(nums, a, b)) != tgt)
    {
      if(pi < tgt)
      {
        a = pi + 1;
      }
      else if(pi > tgt)
      {
        b = pi - 1;
      }
    }
    return nums[pi];
    }
};



