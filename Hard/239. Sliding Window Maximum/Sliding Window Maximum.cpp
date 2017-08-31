#include <bits/stdc++.h>
using namespace std;

/* Given an array nums, there is a sliding window of size k which is moving from the very left
 * of the array to the very right. You can only see the k numbers in the window. Each time the
 * sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

*************************************************************************************/

/*solution1: */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty() || nums.size() < k) { return res; }
        deque<int> q;//store the index;
        for(int i = 0; i < nums.size(); i++){
            //check deque capacity and distance between front element and new element
            if(!q.empty() && q.front() == i-k) { q.pop_front(); }

            //maintenence the deque: 1, before adding the new element, maintain the order
            while(!q.empty() && nums[q.back()] < nums[i]) { q.pop_back(); }//make sure new element is the smallest in deque
            //2, then add new element
            q.push_back(i);

            //check the start point where we need output the max of window, it should be started when i = k-1 [0,..k-1, k,..]
            if(i>=k-1){
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};












