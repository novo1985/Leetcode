#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/***Given an array and a value, remove all instances of that value in place and return the new length.
 * [1,2,2,3,4,4,5,6,6,6] if given value = 6, the return length is 7
***/
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    unordered_map<int, int> nums_map; // key is element, value is frequency
    int n = nums.size();
    for(int i = 0; i < n; ++i){ // record the frequency of each element in O(n).
      nums_map[nums[i]]++;
    }

    if(nums_map.find(val) == nums_map.end()){ // could not find the iterator which key is val.
      return n;
    }

    // task1: else we can find the key, get its frequency
    int x = nums_map[val];
    n = n - x;
    // task2: we need delete all these element with value = val
    for(auto iter = nums.begin(); iter != nums.end();){ // when delete iterator, be care about the boundary!
      if(*iter == val) {
        iter = nums.erase(iter);
      } else { // if not found, iter increment
        iter++;
      }
    }
    return n;
  }
};
int main() {
  Solution test;
  vector<int> v = {2,3,3,2};
  cout << test.removeElement(v, 2) << endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}