#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given a matrix of m x n elements (m ms, n numns), return all elements of the matrix
 * in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. ****************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      if(matrix.empty() || matrix[0].empty()) { return res; }
      int m = matrix.size();
      int n = matrix[0].size();
      int cycle = m > n ? (n + 1)/2 : (m + 1)/2; // To calculate # of cycles
      int height = m, width = n;
      for(int i = 0; i < cycle; i++, height -= 2, width -= 2){
        for(int col = i; col < i + width; col++){// left direction
          res.push_back(matrix[i][col]);
        }
        for(int row = i+1; row < i + height; row++){ // down direction
          res.push_back(matrix[row][i+width-1]);
        }

        if(height == 1 || width == 1){ break; }

        for(int col = i + width - 2; col >= i; col--){ // right direction
          res.push_back(matrix[i+height-1][col]);
        }
        for(int row = i + height - 2; row > i; row--){ // up direction
          res.push_back(matrix[row][i]);
        }
      }
      return res;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty()) return ret;
        int m = matrix.size(), n = matrix[0].size();
        int nlvl = (min(m,n)+1)/2;
        for(int i=0; i<nlvl; i++) {
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            if(lastRow==i) {    // one row remain
                for(int j=i; j<=lastCol; j++)
                    ret.push_back(matrix[i][j]);
            }
            else if(lastCol==i) {   // one col remain
                for(int j=i; j<=lastRow; j++)
                    ret.push_back(matrix[j][i]);
            }
            else {
                for(int j=i; j<lastCol; j++)
                    ret.push_back(matrix[i][j]);
                for(int j=i; j<lastRow; j++)
                    ret.push_back(matrix[j][lastCol]);
                for(int j=lastCol; j>i; j--)
                    ret.push_back(matrix[lastRow][j]);
                for(int j=lastRow; j>i; j--)
                    ret.push_back(matrix[j][i]);
            }
        }
        return ret;

    }
};


















