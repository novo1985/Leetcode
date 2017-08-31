#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Given an array S of n integers, are there elements a, b, c, and d in S such that
 * a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> res;
      int n = nums.size();
      if(n < 4) { return res; }
      sort(nums.begin(), nums.end());
      for(int k = 0; k < n-3; k++){ //
        int reminder_1 = target - nums[k];
        for(int j = k+1; j < n-2; j++){
          //how to remove duplicate I?????????
          if(j > k+1 && num[j]==num[j-1]) continue;
          int reminder_2 = reminder_1 - nums[j];
          int left = j+1, right = n-1;
          while(left < right){
            if(nums[left] + nums[right] == reminder_2){
              res.push_back({nums[k], nums[j], nums[left],nums[right]});
              //remove duplicate II
              while(nums[left] == nums[left + 1]) { left++;}
              while(nums[right] == nums[right - 1]) { right--;}
              left++;
              right--;
            }else if(nums[left] + nums[right] > reminder_2 ){
              right--;
            }else{
              left++;
            }
          }
        }
      }
      return res;
    }
};


/* 在这里为了避免重复项，我们使用了STL中的set，其特点是不能有重复，如果新加入的数在set中原本就存在的话，
 * 插入操作就会失败，这样能很好的避免的重复项的存在。*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        set<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out;
                        out.push_back(nums[i]);
                        out.push_back(nums[j]);
                        out.push_back(nums[left]);
                        out.push_back(nums[right]);
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int> > (res.begin(), res.end());
    }
};


/* recursive k-sum*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> output;
        sort(nums.begin(), nums.end());
        K_sum(nums, 0, nums.size()-1, target, 4, output, res);
        return res;
    }
    void K_sum(vector<int>& nums, int start, int end, int target, int k, vector<int>& output,
      vector<vector<int>>& res){
      if(k<=0) return;
      if(k==1) {
        for(int i=start; i<=end; i++) {
            if(nums[i]==target) {
                output.push_back(target);
                res.push_back(output);
                output.pop_back();
                return;
            }
        }
      }
      if(k == 2){
        two_sum(nums, start, end, target, output, res);
        return;
      }
      else{
        for(int i = start; i <= end - k + 1; i++){
            if(i > start && nums[i]==nums[i-1]) continue; // ???
            output.push_back(nums[i]);
            K_sum(nums, i+1, end, target-nums[i], k-1, output, res);
            output.pop_back();
        }
      }
    }
    void two_sum(vector<int>& nums, int start, int end, int target, vector<int>& output,
      vector<vector<int>>& res){
      while(start < end){
        if(nums[start] + nums[end] == target){
          output.push_back(nums[start]);
          output.push_back(nums[end]);
          res.push_back(output);
          output.pop_back();
          output.pop_back();
          while(nums[start] == nums[start+1]){start++;}
          while(nums[end] == nums[end - 1]){end--;}
          start++;
          end--;
        }else if(nums[start] + nums[end] > target){
          end--;
        }else{
          start++;
        }
      }
    }

};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> allSol;
        vector<int> sol;
        sort(num.begin(),num.end());
        kSum(num, 0, num.size()-1, target, 4, sol, allSol);
        return allSol;
    }

    void kSum(vector<int> &num, int start, int end, int target, int k, vector<int> &sol, vector<vector<int>> &allSol) {
        if(k<=0) return;
        if(k==1) {
            for(int i=start; i<=end; i++) {
                if(num[i]==target) {
                    sol.push_back(target);
                    allSol.push_back(sol);
                    sol.pop_back();
                    return;
                }
            }
        }

        if(k==2) {
            twoSum(num, start, end, target, sol, allSol);
            return;
        }

        for(int i=start; i<=end-k+1; i++) {
            if(i>start && num[i]==num[i-1]) continue;
            sol.push_back(num[i]);
            kSum(num, i+1, end, target-num[i], k-1, sol, allSol);
            sol.pop_back();
        }
    }

    void twoSum(vector<int> &num, int start, int end, int target, vector<int> &sol, vector<vector<int>> &allSol) {
        while(start<end) {
            int sum = num[start]+num[end];
            if(sum==target) {
                sol.push_back(num[start]);
                sol.push_back(num[end]);
                allSol.push_back(sol);
                sol.pop_back();
                sol.pop_back();
                start++;
                end--;
                while(num[start]==num[start-1]) start++;
                while(num[end]==num[end+1]) end--;
            }
            else if(sum<target)
                start++;
            else
                end--;
        }
    }
};




