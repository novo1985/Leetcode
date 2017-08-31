class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumGen(nums, 0);
    }

    vector<vector<int>> threeSumGen(vector<int>& nums, int target){
        vector<vector<int>> res;
        vector<int> sol;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){// A[i], find A[j] + A[k] = target - A[i];
            if(i > 0 && nums[i] == nums[i-1]) { continue; }
            int j = i+1, k = n-1;
            while(j < k){
                if(nums[j] + nums[k] == target - nums[i]){
                    sol.push_back(nums[i]);
                    sol.push_back(nums[j]);
                    sol.push_back(nums[k]);
                    res.push_back(sol);
                    j++;
                    k--;
                    sol.clear();
                    while(nums[j] == nums[j-1]){j++;}
                    while(nums[k] == nums[k+1]){k--;}
                }
                else if(nums[j] + nums[k] > target - nums[i]){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return res;
    }
};







