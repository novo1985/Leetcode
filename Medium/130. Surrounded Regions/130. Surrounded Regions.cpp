/* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) {
          return;
        }
        //if boundary has "O", DFS start from boundary "0", label, these O donot need change to X
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(i == 0 || i == m-1 || j == 0 || j == n-1){
              if(board[i][j] == 'O') {
                solveDFS(board, i, j);
              }
            }
          }
        }
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == '$') board[i][j] = 'O';
          }
        }
    }

    void solveDFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O')
                solveDFS(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O')
                solveDFS(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                solveDFS(board, i + 1, j);
            if (j > 1 && board[i][j - 1] == 'O')
                solveDFS(board, i, j - 1);
        }
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) {
          return;
        }
        //if boundary has "O", DFS start from boundary "0", label, these O donot need change to X
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(i == 0 || i == m-1 || j == 0 || j == n-1){
              if(board[i][j] == 'O') {
                dfssearch(i, j, board);
              }
            }
          }
        }
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == '$') board[i][j] = 'O';
          }
        }
    }

    void dfssearch(int i, int j, vector<vector<char>>& board) {
      if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) { return; }

      if(board[i][j] == 'O') {
        board[i][j] = '$';
        dfssearch(i+1, j, board);
        dfssearch(i-1, j, board);
        dfssearch(i, j-1, board);
        dfssearch(i, j+1, board);
      }
    }
};






