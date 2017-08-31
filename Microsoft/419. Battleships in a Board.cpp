
/*solution1: DFS, with extra space store visited information */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int m = board.size(), n = board[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    dfs(board, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] == '.') return;
        visited[i][j] = true;
        //dfs(board, visited, i - 1, j);
        dfs(board, visited, i + 1, j);
        //dfs(board, visited, i, j - 1);
        dfs(board, visited, i, j + 1);
    }
};

//solution2: o(1) space, o(n)time
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return 0;
        int res = 0, m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            //find the head of battleship: right---> or down---->
            if(board[i][j] == '.') { continue; }
            if(i > 0 && board[i-1][j] == 'X') { continue; }
            if(j > 0 && board[i][j-1] == 'X') { continue; }
            res++;
          }
        }
        return res;
    }
};





