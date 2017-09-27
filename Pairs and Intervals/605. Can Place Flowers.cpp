/* Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 *
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 *
 * flowers cannot be planted in adjacent plots
 */


/* find intervals of "0,0, ..."
 * if interval.length < 3, which mean nothing, no more flowers can be planted in this intervals
 * Find all intervals, which size bigger than 3
 * 1) pass through flowerbed, record all qualified intervals
 * 2) calculate how many flowers can be planted
 **/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      //corner case: empty bed
      if(flowerbed.empty()) { return false; }

      //corner case: flowerbed = [0], n=1
      if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1){
          return true;
      }

      //vector<int> intervals_length;
      int res = 0;
      for(int i = 0; i < flowerbed.size();) {
        if(flowerbed[i] == 0){
          int j = i;
          while(j < flowerbed.size() && flowerbed[j] == 0) {
            j++;
          }
          if(i == 0 && j == flowerbed.size()) {//all points are "0"
            res += (j-i+1)/2;
          }else if(i == 0 || j == flowerbed.size()){//two ending points are "0"
            res += (j-i)/2;
          }else {
              res += (j-i-1)/2;
          }
          i = j + 1;
        }else {
          i++;
        }
      }

     /* int res = 0;
      for(const auto& it : intervals_length) {
        res += (it-1)/2;
      }*/
      return res >= n;
    }
};















