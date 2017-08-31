#include <bits/stdc++.h>
using namespace std;

/* Given two words (beginWord and endWord), and a dictionary's word list, find the length of
 * shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings).
Please reload the code definition to get the latest changes.  *****************************/

//shortest path, length, depth Using BFS(queue, "")
//solution1: time limited!
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return 0; }
        queue<string> q;
        q.push(beginWord);//first level
        q.push("");//seperate level;
        int res = 1;
        while(!q.empty()){
          string str = q.front();
          q.pop();
          if(str != ""){
            for(int i = 0; i < str.size(); i++){// all possible start point of transformation
              char temp = str[i];//store orignal char
              for(char c = 'a'; c <= 'z'; c++){
                //change each start point [i] to c, all possibility
                if(c == temp) { continue; }// c != temp, we need change
                str[i] = c;
                if(str == endWord){//endWord must be in the list, so don't need check str in the list
                  res++;//
                  return res;
                }
                if(find(wordList.begin(), wordList.end(), str) != wordList.end()){// after change, str in the list, continue;
                  q.push(str);
                  wordList.erase(find(wordList.begin(), wordList.end(), str));
                }
              }
              str[i] = temp;// next start point, only change one char, the previous reset
            }
          }
          else if(str == "" && !q.empty()){//enter to the next level
            res++;
            q.push("");
          }
        }
        return 0;
    }
};
//solution2: modify the BFS
class Solution{
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());// store wordlist into set, easy find
    if(dict.count(endWord) == 0) { return 0; } //no target in the wordlist
    queue<string> q;
    q.push(beginWord);
    q.push("");
    int res = 1;
    while(!q.empty()){
      string str = q.front();
      q.pop();
      if(str != ""){// the start point of change can be each index;
        for(int i = 0; i < str.size(); i++){
          char temp = str[i];//store original ch, reset after new start
          for(char c = 'a'; c <= 'z'; c++){//ASCII VALUE, replace str[i] by all possible 26-1 value
            if(c == str[i]){ continue; } // 26-1;
            str[i] = c; // change the value;
            if(str == endWord){
              res++;
              return res;
            }else{
              if(dict.count(str) == 1){
                q.push(str);
                dict.erase(str);
              }
            }
          }
          str[i] = temp;
        }
      }
      else if(str == "" && !q.empty()){
        res++;
        q.push("");
      }
    }
    return 0;
  }
};
//solution3: add hashmap, do not need erase wordlist;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (dict.count(newWord) && newWord == endWord) return m[word] + 1;
                    if (dict.count(newWord) && !m.count(newWord)) {
                        q.push(newWord);
                        m[newWord] = m[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};




























