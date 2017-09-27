/* Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation:
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}*/

//solution: There is a cycle!!!
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
      int maxlen = 0;
      if(nums.empty()) { return maxlen; }
      int n = nums.size();
      vector<bool> visited(n, false);
      for(int i = 0; i < n; i++) {
        if(visited[i]) { continue; }
        maxlen = max(maxlen, helper(nums, i, visited));
      }
      return maxlen;
    }
    int helper(vector<int>& nums, int start, vector<bool>& visited) {
      int i = start, count = 0;
      while(count == 0 || i != start) {//cycle
        visited[i] = true;
        i = nums[i];
        count++;
      }
      return count;
    }
};
//no recursion
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
      int maxlen = 0;
      if(nums.empty()) { return maxlen; }
      vector<bool> visited(nums.size(), false);
      for(int i = 0; i < nums.size(); i++) {
        if(visited[i]) { continue; }
        int count = 0, start = i;
        while(count == 0 || start != i){
          visited[start] = true;
          start = nums[start];
          count++;
        }
        maxlen = max(maxlen, count);
      }
      return maxlen;
    }
};

//no extra space
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
      int maxlen = 0;
      if(nums.empty()) {return maxlen; }
      for(int i = 0; i < nums.size(); i++) {
        /* 对于每一个index， 重置count = 1*/
        int count = 1;
        while(i != nums[i] && nums[i] != nums[nums[i]]) {// cycle！
          swap(nums[i], nums[nums[i]]);//交换，将其放在原本应该在的地方，[0,..,n-1], nums[i] == i!
          count++;
        }
        maxlen = max(maxlen, count);
      }
      return maxlen;
    }
};







