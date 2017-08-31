#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>
//#include <utility>
//#include <unordered_map>
using namespace std;

/* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 ****************************************************/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int>(n, 0)); // initialization
        int c = (n+1)/2; // how many cycles?
        int nums = 1; //start at "1"
        for(int i = 0; i < c; i++){
          int last = n-1-i;
          // left direction
          for(int j = i; j <= last; j++){
            res[i][j] = nums++;
          }
          // down direction
          for(int j = i; j <=last; j++){
            res[j][last] = nums++;
          }
          // right direction
          for(int j = last; j > i; j--){
            res[last][j] = nums++;
          }
          // up direction
          for(int j = last; j > i; j--){
            res[j][i] = nums++;
          }
        }
        if(n%2 == 1){
          res[n/2][n/2] == nums;
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int nlvl = n/2;
        int val = 1;
        for(int i=0; i<nlvl; i++) {
            int last = n-1-i;
            for(int j=i; j<last; j++)
                ret[i][j] = val++;
            for(int j=i; j<last; j++)
                ret[j][last] = val++;
            for(int j=last; j>i; j--)
                ret[last][j] = val++;
            for(int j=last; j>i; j--)
                ret[j][i] = val++;
        }
        if(n%2==1) ret[n/2][n/2] = val;
        return ret;
    }
};



//method 2:
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res(n,vector<int>(n,0));
        if (n==0){return res;}
        int i=1;
        int x = 0;
        int y = 0;
        res[0][0]=i++;
        while (i<=n*n){
            while (y+1<n && res[x][y+1]==0){   // keep going right
                res[x][++y]=i++;
            }
            while (x+1<n && res[x+1][y]==0){   // keep going down
                res[++x][y]=i++;
            }
            while (y-1>=0 && res[x][y-1]==0){  // keep going left
                res[x][--y]=i++;
            }
            while (x-1>=0 && res[x-1][y]==0){  // keep going up
                res[--x][y]=i++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int>> ans(n, row);
        if(n <= 0)  return ans;

        int x = 0, y = 0;
        int num = 0;
        int a, b, c, d;
        for(int i=n-1; i>=0; i=i-2)
        {
            if(i == 0)  ans[x][y] = n*n;
            else
            {
                for(a = 0; a < i; a++)
                {
                    ans[x][y+a] = ++num;
                }
                y = y + i;

                for(b = 0; b < i; b++)
                {
                    ans[x+b][y] = ++num;
                }
                x = x + i;

                for(c = 0; c < i; c++)
                {
                    ans[x][y-c] = ++num;
                }
                y = y - i;

                for(d = 0; d < i; d++)
                {
                    ans[x-d][y] = ++num;
                }
                x = x - i + 1;
                y = y + 1;
            }
        }
        return ans;
    }
};
