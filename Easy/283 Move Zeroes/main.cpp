#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    class Solution {
    public:
      void moveZeroes(vector<int>& nums) {
        for(auto it = 0; it < nums.size();) {
          if (nums[it] == 0) {
            nums.erase(nums.begin() + it);
            nums.push_back(0);
          } else {
            it++;
          }
          cout << it << endl;
        }
      }
    };

    /**
     * for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
     * */



    int cursor = 0;
    for(int i=0; i<nums.size(); i++)
    {
      if(nums[i] != 0)
      {
        nums[cursor] = nums[i];
        cursor++;
      }
    }

    for(int i=cursor; i<nums.size(); i++)
    {
      nums[i] = 0;
    }
  }
};

int main() {
  Solution test;
  vector<int> nums ={1,0,0,1,0,1};
  test.moveZeroes(nums);
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << endl;
  }
  std::cout << "Hello, World!" << std::endl;
  return 0;
}