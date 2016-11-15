#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> m;
    if(nums.empty()){
      return false;
    }
    for(auto& iter : nums){
      m[iter]++;
    }
    bool duplicate = false;
    for(auto& iter2 : m){
      if(iter2.second > 1){
        duplicate = true;
      }
    }
    return duplicate;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}