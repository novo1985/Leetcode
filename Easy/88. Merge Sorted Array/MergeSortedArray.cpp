#include <iostream>
#include <vector>
using namespace std;

/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * The number of elements initialized in nums1 and nums2 are m and n respectively. */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      //backward!
        int pos = m + n - 1 , i = m - 1 , j = n - 1;
        while (i >= 0 && j >= 0)
            nums1[pos--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        while (i >= 0)
            nums1[pos--] = nums1[i--];
        while (j >= 0)
            nums1[pos--] = nums2[j--];
    }
};