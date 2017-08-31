#include <iostream>
#include <vector>
using namespace std;

/* Rotate an array of n elements to the right by k steps. */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      // k % n == 0, same vector
      int n = nums.size();
      if(k % n == 0) { return; }
      int m = k % n;
      vector<int> vi = nums;
      for(int i = 0; i < n; i++){
        nums[(i+m)%n] = vi[i];
      }
      return;
    }
};

class Solution{
public:
  void rotate(vector<int>& nums, int k) {
      // k % n == 0, same vector
      int n = nums.size();
      if(k % n == 0) { return; }
      int m = k % n;
      //no extra space ???
      for(int i = 0; i < n; i++){

      }
  }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        for (int i = 0; i < n - k; ++i) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};