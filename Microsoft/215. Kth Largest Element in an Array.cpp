class Solution{
public:
  int findKthLargest(vector<int>& nums, int k){
    if(nums.empty() || nums.size() < k) { return -1; }
    priority_queue<int, vector<int>, greater<int>> q; //minimum heap
    for(int i = 0; i <= k - 1; i++) {
      q.push(nums[i]);
    }
    for(int j = k; j < nums.size(); j++) {
      if(nums[j] > q.top()) {
        q.pop();
        q.push(nums[j]);
      }
    }
    return q.top();
  }
};