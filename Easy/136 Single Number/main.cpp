#include <iostream>
#include <vector>
using namespace std;

class Single_Number{
public:
  //constructor;
  Single_Number(vector<int>& v) : nums(v) {}

  // function of finding single number, which require a linear runtime.
  int singlenumber(){
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
      res ^= nums[i] ;
    }
    return res;
  }

public:
  vector<int> nums;
};


int main() {
  vector<int> a = {1,2,3,4,5,6,1,2,3,4,5};
  Single_Number test(a);
  test.singlenumber();
  cout << "the single number is " << test.singlenumber() << endl;
  return 0;
}