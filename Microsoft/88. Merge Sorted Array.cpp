//solution1: two pointers, time o(m+n), space o(1)
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//using 'at' operation
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //nums1 size m+n;
        int i = m-1;//end of old nums1
        int j = m+n-1;//end of new nums1
        int k = n-1;//end of old nums2
        while(k >=0){
          if(i >= 0 && nums1[i] > nums2[k]) {
            nums1[j] = nums1[i];
            i--;
            j--;
          }else{
            nums1[j] = nums2[k];
            k--;
            j--;
          }
        }
    }
};



