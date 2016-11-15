#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    vector<int> res;
    for(auto& iter : nums1){
      m1[iter]++;
    }

    for(auto& iter2 : nums2){
      m2[iter2]++;
    }

    for(auto& iter1 : m1){
      auto iter2 = m2.find(iter1.first);
      int i = 0;
      if(iter2 != m2.end()){
        i = min(iter1.second, iter2->second);
        for(int j = 0; j < i; j++){
          res.push_back(iter1.first);
        }
      }
    }

    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}