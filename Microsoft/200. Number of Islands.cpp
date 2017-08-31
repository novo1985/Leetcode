//solution1: DFS: expand each island as far as possible, when DFS stop, island finish. count++
class Solution{
public:
  int numIslands(vector<vector<char>>& grid){
    //base case: grid is empty!
    if(grid.empty() || grid[0].empty()) { return 0; }
    //defind row = m; col = n
    int m = grid.size(), n = grid[0].size();
    //how to record visited point? avoid endless DFS
    int res = 0;
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        //island start must be at '1'
        if(grid[i][j] == '1' && visited[i][j] == false){
            //cout << res << endl;
          dfs(i, j, grid, visited);
          res++;
            //cout << res << endl;
        }
      }
    }
    return res;
  }

  void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    //boundary check
    if(i < 0 || i >= grid.size()) { return; }
    if(j < 0 || j >= grid[0].size()) { return; }
    if(visited[i][j] == true || grid[i][j] == '0') { return; }
    visited[i][j] = true;
    dfs(i+1, j, grid, visited);//down
    dfs(i-1, j, grid, visited);//up
    dfs(i, j+1, grid, visited);//right
    dfs(i, j-1, grid, visited);//left
  }
};