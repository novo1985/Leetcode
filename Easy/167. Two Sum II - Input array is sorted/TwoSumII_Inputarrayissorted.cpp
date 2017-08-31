#include <iostream>
#include <vector>
using namespace std;

/* Given an array of integers that is already sorted in ascending
 * order, find two numbers such that they add up to a specific target
 * number.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      //two pointers: start & end
      int i = 0;
      int j = numbers.size()-1;
      vector<int> res;
      while(i < j){
        if(numbers[i] + numbers[j] == target){
          res.push_back(i);
          res.push_back(j);
          break;
        }
        else if(numbers[i] + numbers[j] > target){
          j--;
        }
        else{
          i++;
        }
      }
      return res;
    }
};