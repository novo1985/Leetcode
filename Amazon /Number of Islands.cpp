#include <bits/stdc++.h>
using namespace std;

/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island
 * is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3*/

//solution1. DFS, start from [i][j] == 1, search, how far you can reach, when finished count++;
class Solution{
public:
  int numIslands(vector<vector<char>>& grid){
    if(grid.empty() || grid[0].empty()) { return 0; }
    int row = grid.size(), col = grid[0].size();
    int res = 0;//return value
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(grid[i][j] == '1'){//start point!
          DFSsearch(i, j, grid);
          res++;//which search finished, it extends as far as possible
        }
      }
    }
    return res;
  }

  void DFSsearch(int row, int col, vector<vector<char>>& grid){
    //ending conditions
    if(row < 0 || row >= grid.size()) return;//finish
    if(col < 0 || col >= grid[0].size()) return;//finish
    if(grid[row][col] == '0') return;//finish
    //now we set grid[i][j] == '0', to avoid repeat search by backing
    grid[row][col] == '0';
    DFSsearch(row+1, col, grid);//up
    DFSsearch(row-1, col, grid);//down
    DFSsearch(row, col+1, grid);//right
    DFSsearch(row, col-1, grid);//left
    //search(i, j)finished
  }
};











