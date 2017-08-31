#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<vector<int>> res;
       if (rowIndex < 0) {return res[0];}
       vector<int> row;
       //base rows: res[0] & res[1]
       row.push_back(1);
       res.push_back(row);
       if(rowIndex == 0) {return res[0];}
       row.push_back(1);
       res.push_back(row);
       if(rowIndex == 1) {return res[1];}

       for(int i = 2; i <= rowIndex; i++){
        vector<int> temp(i+1, 1); // ith row has i+1 element, initialize all to "1"
        for(int j = 1; j < i; j++){ // the first and last element j=0 & j=i are always "1"
          temp[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(temp);
       }
       return res[rowIndex];
    }
};

//o(k) space
class Solution{
public:
  vector<int> getRow(int rowIndex){
    vector<int> row (rowIndex+1, 1);
    int prev = 1;
    for(int i = 2; i <= rowIndex; i++){// update start form i = 2 : {1,2,1}
      for(int j = 1; j < i; j++){// [0,.., i-1] = {1,1,1,1,...}
          int temp = row[j];
          row[j] += prev;
          prev = temp;
      }
    }
    return row;
  }
};