#include <bits/stdc++.h>
using namespace std;

/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will
not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".    ************/

//solution1: time limited, using hash table, compare two hash table
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.empty() || s.size() < p.size()) { return res; }
        int m = s.size();
        int n = p.size();
        unordered_map<char, int> map; //key = char, int = frequency
        for(const auto& a : p) { map[a]++; }

        for(int i = 0; i <= m-n; i++){//string s index start point
          unordered_map<char, int> temp;
          for(int j = i; j <= n+i-1; j++){//match range
            temp[s[j]]++;
          }
          if(map == temp){
            res.push_back(i);
          }
        }
        return res;
    }
};

//solution2: hash table, but update when go through the index
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.empty() || s.size() < p.size()) { return res; }
        int m = s.size();
        int n = p.size();
        //unordered_map<char, int> map; //target key = char, int = frequency
        //unordered_map<char, int> win;//在字符串s 上滑动更新
        vector<int> map(256,0), win(256,0);
        for(int i = 0; i < n; i++) { map[p[i]]++; win[s[i]]++;}
        if(map == win) { res.push_back(0);}//initial state
        for(int i = 1; i <= m-n; i++) {
          //update window
          win[s[i-1]]--;//delete 前一个元素
          win[s[n+i-1]]++;// 增加后一个元素
          if(map == win){
            res.push_back(i);
          }
        }
        return res;
    }
};
















