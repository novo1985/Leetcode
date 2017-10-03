/* makes sum of min(ai, bi) for all i from 1 to n as large as possible.*/


//O(nlgn), sort, then sum of all odd index;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if((i+1) % 2 == 1) {
                sum += nums[i];
            }
        }
        return sum;
    }
};