/*Greedy algorithm
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       if(pairs.empty()) { return 0; }
       sort(pairs.begin(), pairs.end(), []
            (const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            });
       int res = 0;
       while(!pairs.empty()){
           int end = pairs[0][1];
           res++;
           int i = 0;
           while(i < pairs.size()){
               if(pairs[i][0] <= end){
                   iter++;
               }else{
                   break;
               }
           }
           pairs.earse(pairs.begin(), iter);
       }
        return res;
    }
};
*/

//solution: dp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       if(pairs.empty()) { return 0; }
       //sorted pairs by finish time;
       sort(pairs.begin(), pairs.end(), []
            (const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            });
       //dp[i], defined as max chain , which ending with index = i, including pairs[i].
       //dp[i] = 1               if there doesn't exist k [0,..,i-1], which pairs[k][1] < pairs[i][0]
       //     or 1 + max{dp[k]}  which pairs[k][1] < pairs[i][0]
       vector<int> dp(pairs.size(), 1);//dp[0] = 1;
       for(int i = 1; i < pairs.size(); i++){
          int temp = 1;//only include itself
          int MAXI = 0;
          for(int k = 0; k < i; k++){//all possible k
            if(pairs[k][1] < pairs[i][0]){
              MAXI = max(MAXI, dp[k]);
            }
          }
          dp[i] = temp + MAXI;
       }

       int len = INT_MIN;
       for(const auto& a : dp){
        if(a > len){ len = a; }
       }
       return len;
    }
};



















