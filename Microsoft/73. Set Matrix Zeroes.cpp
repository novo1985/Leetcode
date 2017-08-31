//first row and col!
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matirx[0].empty()) { return; }
        int m = matrix.size(), n = matrix[0].size();
        //we treat first row and col in the final, they used as axis,
        //we need record original "0" information
        bool firstrowZero = false, firstcolZero= false;
        for(int i = 0; i < m; i++) {
          if(matrix[i][0] == 0) firstcolZero = true;
        }
        for(int j = 0; j < n; j++) {
          if(matrix[0][j] == 0) firstrowZero = true;
        }
        //go over through matrix[1,..,m-1][1,..,n-1]
        for(int i = 1; i < m; i++) {
          for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0){//set axis value to "0"
              matrix[i][0] = 0;
              matrix[0][j] = 0;
            }
          }
        }
        //update matrix[1,..,m-1][1,..,n-1]
        for(int i = 1; i < m; i++) {
          for(int j = 1; j < n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
              matrix[i][j] = 0;
            }
          }
        }

        //update first row and col
        if(firstrowZero) {
          for(int j = 0; j < n; j++) {
            matrix[0][j] = 0;
          }
        }
        if(firstcolZero) {
          for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
          }
        }
    }
};