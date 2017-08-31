class Solution{
public:
  void setZeroes(vector<vector<int>>& matrix){
    int row = matrix.size(), col = matrix[0].size();
    /*all the point (i, j) = 0, we label the first row (0, j) and first col(i, 0) as zero, but before
     * change the value, we need record the info if there is zero in the original first row and col */
    bool firstrow_zero = false, firstcol_zero = false;
    for(int i = 0; i < row; i++){
      if(matrix[i][0] == 0) { firstcol_zero = true; }
    }
    for(int j = 0; j < col; j++){
      if(matrix[0][j] == 0) { firstrow_zero = true; }
    }
    //check the points in the left rows and cols time: O(mn), and label the coordinate position
    for(int i = 1; i < row; i++){
      for(int j = 1; j < col; j++){
        if(matrix[i][j] == 0){
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    //according to the coordinate position, change the value in the [1,..,row][1,..,col]
    for(int i = 1; i < row; i++){
      for(int j = 1; j < col; j++){
        if(matrix[i][0] == 0 || matrix[0][j] == 0){
          matrix[i][j] = 0;
        }
      }
    }
    //Last update: change the first row and col
    if(firstrow_zero){
      for(int j = 0; j < col; j++) { matrix[0][j] = 0;}
    }
    if(firstcol_zero){
      for(int i = 0; i < row; i++) { matrix[i][0] = 0;}
    }
  }
};