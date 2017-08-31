#include <bits/stdc++.h>
using namespace std;

/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add
 * spaces in s to construct a sentence where each word is a valid dictionary word. You may assume
 * the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].  *******************/

/* solution1: DFS and memorized cache
 * 1) int start = 0; find i within [0,..,n-1]
 * 2) if s.substr(start, i-start+1) can be found in dict, moreover, dfs(i+1) is true;
      cache_map[start].push_back(substr), every key is true!
 * 3) ****/
/*
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if(dfs(0, s, dict, cache_map)){
          return buildstring(cache_map);
        }
        return res;
    }

    bool dfs(int start, string& s, unordered_set<string> dict,
                                    unordered_map<int, pair<bool, vector<string>>> cache_map){
      if(cache_map.count(start)) { return cache_map[start].first; }
      for(int i = start; i < s.size(); i++){
        string word = s.substr(start, i-start+1);
        vector<string> str;
        if(dict.count(word) != 0){
          if(i == s.size()-1){
            cache_map[start].first = true;
            cache_map[start].second.push_back(word)
            return true;
          }
          if(dfs(i+1, s, dict, cache_map)){
            cache_map[start].first = true;
            cache_map[start].second.push_back(word)
            return true;
          }
        }
      }
      cache_map[start].first = false;
      return false;
    }

private:
    vector<string> res;
    unordered_map<int, pair<bool,vector<string>> > cache_map;
    vector<string> buildstring(unordered_map<int, pair<bool,vector<string>> > cache_map){
      //start : key = 0 !
    }
};
*/



class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string out;
        unordered_set<string> Dict(wordDict.begin(), wordDict.end());
        vector<bool> possible(s.size() + 1, true);
        wordBreakDFS(s, Dict, 0, possible, out, res);
        return res;
    }
    void wordBreakDFS(string &s, unordered_set<string> &Dict, int start, vector<bool> &possible, string &out, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(out.substr(0, out.size() - 1));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i - start + 1);
            if (Dict.find(word) != Dict.end() && possible[i + 1]) {
                out.append(word).append(" ");
                int oldSize = res.size();
                wordBreakDFS(s, Dict, i + 1, possible, out, res);
                if (res.size() == oldSize) possible[i + 1] = false;
                out.resize(out.size() - word.size() - 1);
            }
        }
    }
};














