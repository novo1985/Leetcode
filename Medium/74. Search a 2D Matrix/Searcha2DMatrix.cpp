#include <bits/stdc++.h>
using namespace std;

/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has
 * the following properties:

 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,

 * Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true. ********************************************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      //step1: find the row where target locate
      if(matrix.empty() || matrix[0].empty()) { return false; }
      if(matrix[0][0] > target) { return false; } // the first number is bigger than target
      int m = matrix.size();
      int n = matrix[0].size();
      int row = 0;
      for(row = 0; row < m;){
        if(matrix[row][n-1] < target){
          row++;
        }
        else break;
      }
      cout << "the row is " << row << endl;

      if(row >= m) { return false; } // target greater than the last element
      // now we get the value of row, bianry search this row!
      int p = 0, r = n-1;
      while(p < r){
        int m = p + (r-p)/2;
        if(matrix[row][m] == target){
          return true;
        }
        else if(matrix[row][m] > target){
          r = m - 1;
        }
        else{
          p = m + 1;
        }
      }
      return matrix[row][r] == target ? true : false;
    }
};




























