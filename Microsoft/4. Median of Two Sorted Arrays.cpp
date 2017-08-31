//merge into one array o(t) = (m+n) space o(m+n)
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) {
            return 0.0;
        }
        //merge two array together
        int m = nums1.size(), n = nums2.size();
        int i = m-1, j = n - 1, k = m + n - 1;
        vector<int> nums3(k+1, 0);
        while(j >= 0 || i >= 0) {
          if(i >= 0 && j >= 0) {
            nums3[k] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
              //cout << nums1[k] << endl;
            k--;
          }else if(i >= 0){
            nums3[k] = nums1[i--];
              //cout << nums1[k] << endl;
            k--;
          }else {
            nums3[k] = nums2[j--];
            k--;
          }
        }
        for(const auto& it : nums3) { cout << it << " "; }
        double res = 0.0;
        int start = 0, end = nums3.size() - 1;
        int m1 = start + (end - start)/2;
        cout << endl;
        cout << "m1 is " << m1 << endl;
        cout << "nums3[m1] + nums3[m1+1] is " << nums3[m1] + nums3[m1 + 1] << endl;
        if(nums3.size()%2 == 0) {
          res = (double)(nums3[m1] + nums3[m1 + 1])/(double)2;
        }else {
          res = (double)(nums3[m1]);
        }
        return res;
    }
};
//solution2: improve space o(n);
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) {
            return 0.0;
        }
        int m = nums1.size(), n = nums2.size();
        int i = m-1, j = n - 1, k = m + n - 1;
        nums1.resize(k+1, 0);
        while(i >= 0 || j >= 0 ){
          if(i >= 0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
          }else if(i >= 0) {
            nums1[k--] = nums1[i--];
          }else {
            nums1[k--] = nums2[j--];
          }
        }
        for(const auto& it : nums1) { cout << it << " ";}
        int start = 0, end = nums1.size()-1;
        int m1 = start + (end - start)/2;
        double res = 0.0;
        if(nums1.size()%2 == 0) {
          res = (double)(nums1[m1] + nums1[m1+1])/2;
        }else {
          res = (double)nums1[m1];
        }
        return res;
    }
};

//binary search o(t) = lg(m)+lg(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) {
            return 0.0;
        }
        //Find the median, there are two case: total number is odd or even
        int m = nums1.size(), n = nums2.size();
        //find the k th largest number from [0, m+n-1]:
        //k = (m+n)%2 == 1? (m+n-1)/2 : two elements (m+n-1)/2 && (m+n-1)/2 + 1
        int k = (m+n+1)/2;//may be median need two element, but find the mid first
        if((m+n)%2 == 1) {
          return findNumbers(nums1, 0, m-1, nums2, 0, n-1, k);
        }else {
          return (findNumbers(nums1, 0, m-1, nums2, 0, n-1, k) + findNumbers(nums1, 0, m-1, nums2, 0, n-1, k+1))/2;
        }
    }
    double findNumbers(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2,
      int k) {
      if(s1 > e1 && s2 > e2) {
        return 0.0;
      }
      if(s1 > e1) {
        return (double)nums2[s2 + k - 1];
      }
      if(s2 > e2) {
        return (double)nums1[s1 + k - 1];
      }
      int mid1 = s1 + (e1-s1)/2;
      int mid2 = s2 + (e2-s2)/2;
      //now the how many element? (mid1 - s1 + 1) + (mid2 -s2 + 1) in the two regions
      if(nums1[mid1] > nums2[mid2]) {
        if(k <= (mid1 - s1 + 1) + (mid2 -s2 + 1) - 1) {
          return findNumbers(nums1, s1, mid1-1, nums2, s2, e2, k);
        }else {
          return findNumbers(nums1, s1, e1, nums2, mid2+1, e2, k - mid2 + s2 -1);
        }
      }else {// nums1[mid1] <= nums2[mid2]
        if(k <= (mid1 - s1 + 1) + (mid2 -s2 + 1) -1) {
          return findNumbers(nums1, s1, e1, nums2, s2, mid2-1, k);
        }else{
          return findNumbers(nums1, mid1+1, e1, nums2, s2, e2, k - mid1 + s1 - 1);
        }
      }
    }
};





