
//solution1: O(nlogn), sort remove duplicate
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());//avoid duplicate pair
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) { continue; }
            int j = i+1;
            while(j < nums.size()) {
                if(nums[j] - nums[i] == k) {
                    res++;
                    break;
                }else if(nums[j] - nums[i] < k) {
                    j++;
                }else{
                    break;//due to sorted, nums[++j] > nums[j]
                }
            }
        }
        return res;
    }
};

//solution2: o(n), hashmap
class Solution{
public:
  int findPairs(vector<int>& nums, int k){
    if(k < 0) { return 0; }
    unordered_map<int, int> map; // key is nums[i], value is frequency
    int res = 0;
    for(const auto& it : nums) {
      map[it]++;
    }
    if(k > 0){
      for(auto it = map.begin(); it != map.end(); it++){
        if(map.find(it->first+k) != map.end()) { res++; } // map.count(it->first + k) != 0
      }
    }else {
      for(auto it = map.begin(); it != map.end(); it++){
        if(it->second > 1) { res++; }
      }
    }
    return res;
  }
};










