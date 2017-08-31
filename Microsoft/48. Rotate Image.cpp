//just need rotate 1/4 area
//odd, even ==>range
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //the range of 1/4 area
        int row = (n/2)-1, col = (n-1)/2;
        for(int i = 0; i <= row; i++) {
          for(int j = 0; j <= col; j++) {
            //update four value of relative positon
            int temp = matrix[i][j];//store original value
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
          }
        }
    }
};