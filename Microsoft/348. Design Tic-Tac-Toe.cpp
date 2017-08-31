class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));
        int size = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        //valid move
        board[row][col] = player;
        //check if player win the game: four direction
        int i = 0, j = 0;
        for(j = 1; j < size; j++){
            if(board[row][j] != board[row][j-1]) { break; }// left-right
        }
        if(j == size) { return player; }

        for(i = 1; i < size; i++) {
            if(board[i][col] != board[i-1][col]) { break; }// up-down
        }
        if(i == size) { return player; }

        if(row == col) {//one diagram
            for(i = 1; i < size; i++) {
                    if(board[i][i] != board[i-1][i-1]) { break; }
            }
            if(i == size) { return player; }
        }

        if(row + col == size - 1) {//another digram
            for(i = 1; i < size; i++) {
                    if(board[i][size-i-1] != board[i-1][size-i]) { break; }
            }
            if(i == size) {return player; }
        }

        return 0;
    }

private:
    vector<vector<int>> board;
    int size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));
    }

    int move(int row, int col, int player) {
        board[row][col] = player;
        int i = 0, j = 0, n = board.size();
        for (j = 1; j < n; ++j) {
            if (board[row][j] != board[row][j - 1]) break;
        }
        if (j == n) return player;
        for (i = 1; i < n; ++i) {
            if (board[i][col] != board[i - 1][col]) break;
        }
        if (i == n) return player;
        if (row == col) {
            for (i = 1; i < n; ++i) {
                if (board[i][i] != board[i - 1][i - 1]) break;
            }
            if (i == n) return player;
        }
        if (row + col == n - 1) {
            for (i = 1; i < n; ++i) {
                if (board[n - i - 1][i] != board[n - i][i - 1]) break;
            }
            if (i == n) return player;
        }
        return 0;
    }

private:
    vector<vector<int>> board;
};