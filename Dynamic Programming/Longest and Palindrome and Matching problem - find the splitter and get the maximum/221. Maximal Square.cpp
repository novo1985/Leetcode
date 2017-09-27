/* Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's
 * and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.*/

/* the maxarea of square depends of the min-length of "1" in three directions:
 * dia[point]:  point == 1, the longest diagonal "1", ending with point
 * left[point]: point == 1, the longest left line "1", ending with point
 * up[point]:   point == 1, the longest up line "1", ending with point
 *
 * diag[i][i] = diag[i-1][i-1] + 1  if(matrix[i][i] == 1)
 *            = 0                   if(matrix[i][i] == 0)
 * left[i][j] = left[i][j-1] + 1  if(matrix[i][j] == 1)
 *            = 0                 if(matrix[i][j] == 0)
 * up[i][j]   = up[i-1][j] + 1  if(matrix[i][j] == 1)
 *            = 0               if(matrix[i][j] == 0)**********/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      if(matrix.empty() || matrix[0].empty()) return 0;
      int m = matrix.size(), n = matrix[0].size();
      int maxarea = 0;
      vector<vector<int>> diag (m, vector<int>(n, 0));
      vector<vector<int>> left (m, vector<int>(n, 0));
      vector<vector<int>> up (m, vector<int>(n, 0));

      //base case
      for(int j = 0; j < n; j++) {
        up[0][j] = (matrix[0][j] == '1')? 1 : 0;
        diag[0][j] = (matrix[0][j] == '1')? 1 : 0;
        maxarea = max(maxarea, diag[0][j]);
      }

      for(int i = 0; i < m; i++) {
        left[i][0] = (matrix[i][0] == '1')? 1 : 0;
        diag[i][0] = (matrix[i][0] == '1')? 1 : 0;
        maxarea = max(maxarea, diag[i][0]);
      }

      //initialization step2:
    for(int j = 1; j < n; j++) {
        left[0][j] = (matrix[0][j] == '0')? 0 : 1 + left[0][j-1];
        maxarea = max(maxarea, left[0][j]);
    }

    for(int i = 1; i < m; i++) {
        up[i][0] =  (matrix[i][0] == '0')? 0 : 1 + up[i-1][0];
        maxarea = max(maxarea, up[i][0]);
    }

      for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
          if(matrix[i][j] == '1'){
              diag[i][j] = 1 + diag[i-1][j-1];
              left[i][j] = 1 + left[i][j-1];
              up[i][j] = 1 + up[i-1][j];
              int width = min(diag[i][j], min(left[i][j], up[i][j]));
              int area = width * width;
              maxarea = max(maxarea, area);
          }
        }
      }

      return maxarea;

    }
};

/*
the maximal size of the square that can be achieved at point (i, j), denoted as P[i][j]
P[0][j] = matrix[0][j] (topmost row);
P[i][0] = matrix[i][0] (leftmost column);
For i > 0 and j > 0:
if matrix[i][j] = 0, P[i][j] = 0;
if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1.   */
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (!m) return 0;
    int n = matrix[0].size();
    vector<vector<int> > size(m, vector<int>(n, 0));
    int maxsize = 0;
    for (int j = 0; j < n; j++) {
        size[0][j] = matrix[0][j] - '0';
        maxsize = max(maxsize, size[0][j]);
    }
    for (int i = 1; i < m; i++) {
        size[i][0] = matrix[i][0] - '0';
        maxsize = max(maxsize, size[i][0]);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                maxsize = max(maxsize, size[i][j]);
            }
        }
    }
    return maxsize * maxsize;
}








