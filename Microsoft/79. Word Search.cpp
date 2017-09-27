//DFS backtracking
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      //base case: empty board
      if(board.empty() || board[0].empty()) {
        return false;
      }
      int m = board.size(), n = board[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));//avoid repeated visiting
      for(int i = 0; i < m; i++) {
        for(int j = 0 ; j < n; j++) {
          if(board[i][j] == word[0] && dfs(i, j, 0, word, board, visited)) {
            return true;
          }
        }
      }
      return false;//if every start pointer can not found word
    }

    bool dfs(int i, int j, int index, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited) {
      //backtracking: step 1: return condition!
      if(index == word.size() - 1) { return true; }

      visited[i][j] = true;
      //backtracking: step 2: DFS, and updated
      //up
      if(i-1 >= 0 && !visited[i-1][j] && board[i-1][j] == word[index+1]) {
        if(dfs(i-1, j, index+1, word, board, visited)) { return true; }
      }
      //down
      if(i+1 < board.size() && !visited[i+1][j] && board[i+1][j] == word[index+1]) {
        if(dfs(i+1, j, index+1, word, board, visited)) { return true; }
      }
      //left
      if(j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == word[index+1]) {
        if(dfs(i, j-1, index+1, word, board, visited)) { return true; }
      }
      //right
      if(j+1 < board[0].size() && !visited[i][j+1] && board[i][j+1] == word[index+1]) {
        if(dfs(i, j+1, index+1, word, board, visited)) { return true; }
      }
      visited[i][j] = false;

      return false;
    }
};