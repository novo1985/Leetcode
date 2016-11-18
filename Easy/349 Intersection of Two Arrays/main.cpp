#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  // no defined constructor
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    vector<int> res;

    for (int i = 0; i < nums1.size(); i++){
      m1.insert(make_pair(nums1[i], 0));
    }

    for (int j = 0; j < nums2.size(); j++){
      m2.insert(make_pair(nums2[j], 0));
    }

    for (auto& iter2 : m2){
      auto iter1 = m1.find(iter2.first);

      if(iter1 != m1.end()){
        res.push_back(iter2.first);
      }
    }

    for(auto iter = res.begin(); iter != res.end(); iter++){
      cout << *iter << " " << endl;
    }

      return res;

  }
};
int main() {
  Solution test;
  vector<int> n1 = {1,1,2,3,4,4,5,7,7,7,8,10,11,100,1000};
  vector<int> n2 = {1,2,4,4,4,7,8,8,9,100};

  test.intersection(n1,n2);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}