#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place? ****************************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int row = matrix.size()-1;
      vector<vector<int>> temp = matrix;
      for(int i = 0; i <= row; i++){ // row
        for(int j = 0; j <= row; j++){
          matrix[i][j] = temp[row - j][i];
        }
      }
    }
};

//in-place method
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
          for(int j = i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
          }
          reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};










