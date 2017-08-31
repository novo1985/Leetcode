#include <bits/stdc++.h>
using namespace std;

/* Given two words (beginWord and endWord), and a dictionary's word list, find all shortest
 * transformation sequence(s) from beginWord to endWord */

/*solution: BFS */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict(wordList.begin(), wordList.end());//easy to find and check
      vector<vector<string>> res;
      if(dict.count(endWord) == 0) { return res; } //no endWord in the list

      vector<string> out;
      unordered_map<string, bool> map;
      for(const auto& a : dict){map[a] = false;}

      out.push_back(beginWord);
      queue<string> q;
      q.push(beginWord);
      q.push(""); //boundary of level

      while(!q.empty()){
        string str = q.front();
        q.pop();
        if(str != ""){
          string temp = str;
          for(int i = 0; i < temp.size(); i++){
            for(char ch = 'a'; ch <= 'z'; ch++){
              if(ch == temp[i]) { continue; }
              temp[i] = ch;
              if(temp == endword){ out.push_back(temp); res.push_back(out);}
              if(dict.count[temp] != 0 && map[temp] == false){
                q.push(temp);
                map[temp] = true;
              }
            }
          }
        }
      }

    }
};


//solution
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict(wordList.begin(), wordList.end());//easy to find and check
      vector<vector<string>> res;
      if(dict.count(endWord) == 0) { return res; } //no endWord in the list

      //how to keep track all possible path, each string need store its parent strings, one or more
      unordered_map<string, vector<string>> pre_map;//key is current string, val is its parents
      vector<string> parents;
      pre_map[beginWord] = parents; //
    }
};


























