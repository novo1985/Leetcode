#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //to improve the running time, we should get -1 after one O(n) if it is negative result.
    /** we need:(1)current_dif, if current_dif < 0, this current station can not be start
     *          (2)total_dif, if total_dif < 0, return -1;
     */
    int start = 0; // starting from station 0
    int current_dif = 0; // current station dif
    int total_dif = 0; // accumulated dif
    for(int i = 0; i < gas.size(); ++i){
      total_dif += gas[i] - cost[i];
      current_dif = gas[i] - cost[i];
      if(current_dif < 0){
        start = i + 1;
      }
    }

    if(total_dif < 0){ return -1;}
    else{
      return start;
    }
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}