#include <bits/stdc++.h>
using namespace std;

/* Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

//hash table <key>: sorted string;  <value>: vector of strings with same sorted string;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      unordered_map<string, vector<string>> map;
      for(const auto& it : strs){
        string s = it; // keep the original string
        sort(s.begin(), s.end()); // sorted string became the key of map
        map[s].push_back(it);
      }
      for(const auto& a : map){
        res.push_back(a.second);
      }
      return res;
    }
};











