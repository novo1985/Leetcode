#include <iostream>
#include <string>
#include <map>
using namespace std;

/* Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.***************************************/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.size() != t.size()) { return false; }
      //position and frequency!!! using hashmap sorted pair: <key, value>
      map<char, char> m1;
      map<char, char> m2;
      //assign value:
      for(int i = 0; i< s.size(); i++){
        //check, if new key, assign value
        if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()){
          m1[s[i]] = t[i];
          m2[t[i]] = s[i];
        }else{ // if exists, we need check value
          if(m1[s[i]] != t[i] || m2[t[i]] != s[i]){
            return false;
          }
        }
      }
      return true;
    }
};