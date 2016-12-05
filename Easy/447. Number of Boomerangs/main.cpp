#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    /**double distance_twopoint(pair<int, int> n1, pair<int, int> n2){
        double dis = sqrt(pow((n1.first - n2.first), 2) + pow((n1.second - n2.second), 2));
        return dis;
    }

    for(int i = 0; i < points.size(); i++){
        unordered_map<int,
    }
    **/
    int res = 0;
    // all point can be the center, the tuple (center, point1, point2)
    for (int i = 0; i < points.size(); i++) {
      //for each center, we create a hash_table to store all distances or radius
      unordered_map<int, int> m;
      for (int j = 0; j < points.size(); j++) {
        // calculate the distance, using is as key, the number of repeat is value
        int dis = pow((points[i].first - points[j].first), 2) + pow((points[i].second - points[j].second), 2);
        m[dis]++;
      }
      //each center has a hash table, if some distance value is not unique
      //For example, some distance repeat 3 times, which means there are three points have same distance to center
      //(center, point1, point2) there are 3(point1) * 2(point2) different combinations
      //generally, combination is value * (value - 1)
      for (auto iter = m.begin(); iter != m.end(); iter++){
        res += (iter->second) * (iter->second - 1);
      }
    }
    return res;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

