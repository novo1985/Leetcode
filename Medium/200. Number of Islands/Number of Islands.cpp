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
Answer: 3      **********/

//solution1: DFS, keep the original grid, need extra space!
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty() || grid[0].empty()) return 0;
      int row = grid.size();
      int col = grid[0].size();
      vector<vector<bool>> visit(row, vector<bool>(col, false));//unvisited
      int res = 0;
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(grid[i][j] == '1' && visit[i][j] == false){
            DFSisland(grid, i, j, visit);
            res++;
          }
        }
      }
      return res;
    }

    void DFSisland(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visit){
      if(row < 0 || row >= grid.size()) return;
      if(col < 0 || col >= grid[0].size()) return;
      if(grid[row][col] == '0' || visit[row][col] == true) return;
      visit[row][col] = true;

      DFSisland(grid, row-1, col, visit);//
      DFSisland(grid, row+1, col, visit);//
      DFSisland(grid, row, col-1, visit);//
      DFSisland(grid, row, col+1, visit);//
    }
};

//solution2:DFS, destory the original grid
class Solution{
public:
  int numIslands(vector<vector<char>>& grid){
    if(grid.empty() || grid[0].empty()) { return 0;} // empty grid
    int row = grid.size(), col = grid[0].size();
    int nums = 0;//return value
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(grid[i][j] == '1'){
          DFSsearch(i, j, grid);
          nums++;
        }
      }
    }
    return nums;
  }
  void DFSsearch(int row, int col, vector<vector<char>>& grid){
    if(row < 0 || row >= grid.size()) {return;}// up-down direction of dfs end!
    if(col < 0 || col >= grid[0].size()) {return;}// left-right direction of dfs end!
    if(grid[row][col] == '0') { return; }// water, search over
    grid[row][col] = '0'; // avoid back, already visit

    DFSsearch(row+1, col, grid);
    DFSsearch(row-1, col, grid);
    DFSsearch(row, col+1, grid);
    DFSsearch(row, col-1, grid);
  }
};

//SOLUTION: BFS








