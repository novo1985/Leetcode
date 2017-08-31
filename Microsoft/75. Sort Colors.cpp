//counting sort: two-pass

class Solution {
public:
    void sortColors(vector<int>& nums) {
      //value is at most k = 3, range from[0,1,2], counting sort [0,..,k-1]
      //output: sorted numbers
      vector<int> output (nums.size(), 0);
      //create range array, min = 0, max = 2
      int count[3];
      int range = 2;
      memset(count, 0, sizeof(count));
      //calculate the frequency of each number
      for(int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
      }
      //accumalte value indicates position
      for(int j = 1; j <= range; j++) {// j = 0, 1, 2
        count[j] += count[j-1];
      }

      //output array
      for(int i = 0; i < nums.size(); i++) {
        output[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
      }
      for(int i = 0; i < nums.size(); i++) {
        nums[i] = output[i];
      }
    }
};

//one-pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
      //index left = boundary of "0"/"1", let define nums[left] = 1;
      //index right = boundary of "1/2", let define nums[right] = 2;
      // --------left ---------i ------------right
      int left = 0, i = 0;
      int right = nums.size() - 1;
      while(i <= right) {
        if(nums[i] == 0) {
          swap(nums[left], nums[i]);
          left++;
          i++;
        }else if(nums[i] == 1) {
          i++;
        }else {//nums[i] == 2
          swap(nums[i], nums[right]);
          right--;
        }
      }
    }
};














