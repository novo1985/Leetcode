#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int, int> m;
      for(auto& iter : nums){
        m[iter]++;
      }
      int majority = 0;
      int half = nums.size()/2;
      for(auto& iter2 : m){
        if(iter2.second > half){
          majority = iter2.first;
        }
      }
      cout << "the majority element of this array is " << majority << endl;
      return majority;

    }
};

int main() {
  Solution test;
  vector<int> v = {1,2,3,4,5,3,3,3,3};
  test.majorityElement(v);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}