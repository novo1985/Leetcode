class Solution{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> res;
    //base case, empty matrix
    if(matrix.empty()) { return res; }
    //spiral is just like a cycle, how many cycle?
    int m = matrix.size(), n = matrix[0].size();//row and col
    int cycle = (min(m, n) + 1) / 2;//m = 3, n = 3 cycle = 2
    //outer loop ith cycle;
    for(int i = 0; i < cycle; i++) {
      //current cycle last row and last column ?
      int lastrow = m - 1 - i;
      int lastcol = n - 1 - i;
      //special case: if this is the last cycle in not complete cycle
      if(lastrow == i) {
        for(int j = i; j <= lastcol; j++)
         res.push_back(matrix[i][j]);
      }//only one row left
      else if(lastcol == i) {
        for(int k = i; k <= lastrow; k++){
          res.push_back(matrix[k][i]);
        }
      }else{
        for(int j = i; j < lastcol; j++) { // go to right;
          res.push_back(matrix[i][j]);
        }
        for(int k = i; k < lastrow; k++) { // go down
          res.push_back(matrix[k][lastcol]);
        }
        for(int j = lastcol; j > i; j--) { // go left
          res.push_back(matrix[lastrow][j]);
        }
        for(int k = lastrow; k > i; k--) { // go up
          res.push_back(matrix[k][i]);
        }
      }
    }
    return res;
  }
};