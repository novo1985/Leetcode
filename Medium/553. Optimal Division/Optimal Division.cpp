/* Given a list of positive integers, the adjacent integers will perform the float division.
 * For example, [2,3,4] -> 2 / 3 / 4.
 * add any number of parenthesis at any position to change the priority of operations. You should
 * find out how to add parenthesis to get the maximum result,
 *
 * Input: [1000,100,10,2]
 * Output: "1000/(100/10/2)"*/

/* Solution1: Dp: 1)find the biggest divident
 *                2)find the smallest divisor
 *                [a,b,c,d,e,f,g,h]
 * bottom-up: by length, divident alway start at index = 0, but ending in [0,..,k]
 *                       divisor start at index = k+1, end at n-1
 *                       k [0,..,n-2] ****/
class Solution{
public:
  string optimalDivision(vector<int>& nums){
    string res;
    if(nums.empty) { return res; }
    int n = nums.size();
    double[n][n] Max;//store (i,..j) max value
    double[n][n] Min;//store (i,..j) min value

    for(int i = 0; i < n; i++) { //length = 1;
      Max[i][i] = double(nums[i]);
      Min[i][i] = double(nums[i]);
    }
    int[n][n] maxindex;
    int[n][n] minindex;
    for(int len = 2; len <= n; len++){
      for(int i = 0; i <= n - len; i++){//for each length, all possible start point;
        j = len + i - 1;
        Max[i][j] = DBL_MIN, Min[i][j] = DBL_MAX;
        for(k = i; k < j; k++){
          if(Max[i][j] < (Max[i][k]/Min[k+1][j])){
            Max[i][j] = Max[i][k]/Min[k+1][j];
            maxindex[i][j] = k;
          }
          if(Min[i][j] > (Min[i][k]/Max[k+1][j])){
            Min[i][j] = Min[i][k]/Max[k+1][j];
            minindex[i][j] = k;
          }
        }
      }
    }
    vector<int> splitpoint;

  }
};



/* */
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.empty()) return "";
        string res = to_string(nums[0]);
        if (nums.size() == 1) return res;
        if (nums.size() == 2) return res + "/" + to_string(nums[1]);
        res += "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            res += "/" + to_string(nums[i]);
        }
        return res + ")";
    }
};
