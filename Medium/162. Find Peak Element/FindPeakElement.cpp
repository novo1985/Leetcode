#include <bits/stdc++.h>
using namespace std;

/* A peak element is an element that is greater than its neighbors.
* Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
* The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
* You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element
your function should return the index number 2.   **********************/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      srand(time(0)); // use current time as seed for random generator
      vector<int> peak_index;
      int n = nums.size();
      if(n==1) { return 0; }
      if(nums[0] > nums[1]) { peak_index.push_back(0); }
      if(nums[n-1] > nums[n-2]) { peak_index.push_back(n-1); }
      for(int i = 1; i < n-1; i++){
        int j = i+1;
        if(nums[i] > nums[i-1] && nums[i] > nums[j]){
          peak_index.push_back(i);
        }
      }
      for(auto a : peak_index){
          cout << a << endl;
      }
      cout << "the size of peak_index is " << peak_index.size() << endl;
      int random = peak_index.at(rand() % peak_index.size());
      //cout << peak_index.at(rand() % peak_index.size()) << endl;
      return random;
    }
};

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int l = 1, r = A.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;
            if (A[mid] > A[mid-1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};









