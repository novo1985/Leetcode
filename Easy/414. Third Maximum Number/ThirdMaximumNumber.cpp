#include <iostream>
#include <vector>
using namespace std;

/* Given a non-empty array of integers, return the third maximum number in this array. If it does
 * not exist, return the maximum number. The time complexity must be in O(n).  *********/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int64_t first = INT64_MIN, second = INT64_MIN, third = INT64_MIN;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};