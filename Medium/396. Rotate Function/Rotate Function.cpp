//brute force: time limited
class Solution{
public:
    int maxRotateFunction(vector<int>& A) {
      vector<vector<int>> Bk = allRotatedArray(A);
      return getMax(Bk);
    }
    vector<vector<int>> allRotatedArray(vector<int>& A){
      vector<vector<int>> B;
      B.push_back(A);
      int n = A.size();//k = 1,2,..n-1
      for(int k = 1; k <= n-1; k++){
        vector<int> temp = A;
        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());
        B.push_back(temp);
      }
      return B;
    }
    int getMax(vector<vector<int>>& B){
      int max = INT_MIN;
      int k = B.size();
      for(int i = 0; i < k; i++){
        int temp = 0;
        for(int j = 0; j < B[0].size();j++){
          temp += j * B[i][j];
        }
        if(temp > max) { max = temp; }
      }
      return max;
    }
};

/*solution:o(n), f1 - f0 = sum - A.size()* A[A.size()-1];
 *               f2 - f1 = sum - A.size()* A[A.size()-2];*/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int f0 = 0;//base case k = 0 (k%n==0)
        int sum = 0;
        for(int i = 0; i < A.size(); i++){
            f0 += i * A[i];
            sum += A[i];
        }
        int k = A.size() - 1; // remaining different possible k steps rotation
        int max = f0;
        int add = f0;
        for(int j = 1; j <= k; j++){
            int temp = sum - (k+1)*A[A.size()-j] + add;//get the f(j)
            if(temp > max) { max = temp; }
            add = temp;
        }

        return max;
    }
};







