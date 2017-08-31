class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map; // key is nums, value is frequency
        int dupli = 0, miss = 0;
        int sum = 0;
        for(const auto& it : nums){
            sum += it;
            map[it]++;
            if(map[it] == 2){
                dupli = it;
            }
        }
        int normal_sum = (1+nums.size())*nums.size()/2;
        //normal_sum - sum = miss - dupli
        miss = normal_sum - sum + dupli;
        return {dupli, miss};

    }
};