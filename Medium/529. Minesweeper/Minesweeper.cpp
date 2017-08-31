
/* 挖开格需要遵循以下规则：
1.如果挖到地雷，游戏结束，该格由'M'变为'X'。
2.如果挖到空白格且其八邻域中无地雷，该格由'E'变为'B'，并且其八邻域中的每格递归地被挖开。
3.如果挖到空白格但其八邻域中有地雷，该格由'E'变为其八邻域中地雷的数量。
4.当没有格能被挖开时，游戏结束，返回游戏板。*/

/* DFS, start from click position, update board*/
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      //vector<int>& click is pair(x, y)
      //step1: make sure (x, y) valid (in the board)
      if(board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
      }
      dfs(board, click[0], click[1]);
      return board;
    }

    bool inboard(vector<vector<char>>& board, int x, int y){
      if(x < 0 || x >= board.size()) { return false; }
      if(y < 0 || y >= board[0].size()) { return false; }
      return true;
    }

    void dfs(vector<vector<char>>& board, int x, int y){
      if(!inboard(board, x, y)) { return; }
      //step2: find blank, check 8 adajacent position
      int count = 0;//how many mines in the 8 position?
      //create a vector, eight possible move direction of (x, y)
      vector<vector<int>> a = {{-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, { 0, -1}, {1, 1}, {1, 0}, {1, -1}};
      if(board[x][y] == 'E'){
        for(int i = 0; i < 8; i++) {
          if(inboard(board, x+a[i][0], y+a[i][1]) && board[x+a[i][0]][y+a[i][1]] == 'M'){
            count++;
          }
        }
        if(count > 0) {
          board[x][y] = '0' + count;//int to char
        }
        //if count == 0, DFS in 8 directions
        else {
          board[x][y] = 'B';
          for(int i = 0; i < 8; i++){
            dfs(board, x+a[i][0], y+a[i][1]);
          }
        }
      }
    }
};

















