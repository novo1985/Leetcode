#include <bits/stdc++.h>
using namespace std;

/* Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have
the same probability of being returned.     *********************************************/

/* 此题的正确解法是利用到了一个一维数组和一个哈希表，
 * 其中数组用来保存数字，哈希表用来建立每个数字和其在数组中的位置之间的映射 ******/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified
     element. */
    bool insert(int val) {
      if(m.count(val) == 1) { return false; } // val already exists
      nums.push_back(val);
      m[val] = nums.size() - 1;
      return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      if(m.count(val) == 0) { return false; }
      // swap the deleted number and last element of nums, pop the last element
      // OR, update the value of deleted number to last element, pop the last element
      //int last = nums.back();
      int n = nums.size()-1;
      nums[m[val]] = nums[n];
      // update hash table
      m[nums[n]] = m[val];
      m.erase(val);
      nums.pop_back();
      return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
      return nums.at(rand() % nums.size());

    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */








