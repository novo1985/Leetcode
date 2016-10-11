#include <iostream>
#include <vector>
using namespace std;

//Given an array of integers, every element appears three times except for one. Find that single one.

class Single_number_2{
public:
  Single_number_2(const vector<int>& v):nums(v){}

  //O(n), just a linear runtime
  int single_number(){
    vector<int> bit(32,0);
    int res = 0;
    int k = 1;
    int temp;
      for (int j = 31; j >= 0; --j) {
        for (int i = 0; i < nums.size(); ++i){
          // right shift j bit, to make the bit jth at the end of the binary and & with 1 to make the remaining
          // bit zero.
          temp = (nums[i] >> j) & k;
          bit.at(j) += temp;
        }

        temp = (bit.at(j) %= 3) << j;
        res |= temp;
      }
    return res;
  }
public:
  vector<int> nums;
};

int main() {
  vector<int> v = {1,2,3,4,5,6,1,1,2,2,3,3,4,4,5,5};
  Single_number_2 test(v);
  cout << "the single number is " << test.single_number() << endl;
}