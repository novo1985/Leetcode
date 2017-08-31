#include <bits/stdc++.h>
using namespace std;

/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". ***************/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
      return dfs(0, s, "", dict);
    }

    bool dfs(int index, string& s, string out, unordered_set<string> dict){
      if(index == s.size()) { return true; }//or s == out
      vector<vector<string>> candidate;
      for(int i = index; i < s.size(); i++){
        out.append(s[i]).toString();//out  += s[i];
        if(dict.count(out) != 0) { candidate.push_back(out); }
        else{ break;}
      }
      for(const auto& it : candidate){
        int start = it.size();
        if(dfs(start, s, it, dict)){
          return true;
        }
      }
      return false;
    }
};

//solution1: dynamic programming
/* dp[i] defined as true, if s[0,..,i-1] is found in the dict
 * dp[0] is true.
 * dp[i] is true if: 1) for 0 <= k <= i-1 , s[k, i-1] can be found in the dict
 *                   2) dp[k-1] is true; *********************************/

 class Solution{
 public:
    bool wordBreak(string s, vector<string>& wordDict){
      vector<bool> dp(s.size()+1, false);
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
      dp[0] = true;
      for(int i = 0; i < s.size(); i++){
        for(int k = i; k >= 0; k--){
          if(dict.count(s.substr(k, i-k+1)) != 0 && dp[k] == true){ // k = 0?? dp[-1]??
            dp[i+1] = true;
            break;
          }
        }
      }
      return dp[s.size()];
    }
 };

//SOLUTION2: bfs, queue<int>
 class Solution{
 public:
    bool wordBreak(string s, vector<string>& wordDict){
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
      queue<int> q; // store index
      q.push(0);
      unordered_set<int> visited;
      while(!q.empty()){
        int start = q.front();
        q.pop();
        if(visited.count(start) == 0){
          visited.insert(start);
          for(int i = start; i < s.size(); i++){
            string word = s.substr(start, i-start+1);
            if(dict.count(word) != 0){
              if(i == s.size()-1) { return true;}
              q.push(i+1);
            }
          }
        }
      }
      return false;
    }
 };
/*solution3: DFSDepth First Search (DFS), unlike BFS, it will terminate once found a route,
 therefore the best case would be very quick, abandoning the remaining search tree.*/
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
      unordered_map<int, bool> visited;
      return dfs(0, s, visited, dict);
    }
    bool dfs(int start, string& s, unordered_map<int, bool>& visited, unordered_set<string>& dict){
      if(visited.count(start)) { return visited[start];}
      for(int i = start; i < s.size(); i++){
          string word = s.substr(start, i-start+1);
          if(dict.count(word) != 0){
            if(i == s.size()-1){
              visited[start] = true;
              return true;
            }
            if(dfs(i+1, s, visited, dict)){
              visited[start] = true;
              return true;
            }
          }
      }
      visited[start] = false;
      return false;
    }
};



















