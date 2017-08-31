#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate
 * (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains
 * the most water.    ***********/

class Solution {
public:
    int maxArea(vector<int>& height) {
      /* n points (i, ai), i = 1,..,n the solution is find the biggest area!
       * the return value: area = max[(i - j)* min(ai, aj)];
       * A[i, j]: defined as the area using ai & aj;       *****************/
      int n = height.size();
      int A[n][n];
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          A[i][j] = 0;
        }
      }
      int max = 0;
      for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
          A[i][j] = (j - i) * min(height[i], height[j]);
          if(A[i][j] > max){
            max = A[i][j];
          }
        }
      }
      return max;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
      int max_ = 0;
      int left = 0, right = height.size()-1;
      while(left < right){
        max_ = max(max_, (right - left) * min(height[left], height[right]));
        if(height[left] < height[right]){
          left++;
        }else if(height[left] > height[right]){
          right--;
        }else{
          left++;
          right--;
        }
      }
      return max_;
    }
};





