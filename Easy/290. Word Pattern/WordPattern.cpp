#include <iostream>
#include <string>
#include <unodered_map>

using namespace std;

/* Given a pattern and a string str, find if str follows the same pattern.
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.  ********/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
      unordered_map<char, string> m;
      for(int i = 0; i < pattern.size(); i++){
        if(m.find(pattern[i]) == m.end()){ // new key
          m[pattern[i]] = str.substr(0, str.find_first_of(" "));
          str = str.substr(str.find_first_of(" ")+1);
          //str.erase(0, str.find_first_of(" "));
        }else{
          if(m[pattern[i]] != str.substr(0, str.find_first_of(" "))){
            return false;
          }
        }
      }
      return true;
    }
};


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        set<string> set_string;
        istringstream input(str);
        string s;

        for(int i = 0; i < pattern.size(); i++){
            if(input>>s){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != s)return false; //pattern already mapped with some other string
            }
            else {
                if(set_string.count(s)){
                    return false;//string already exist for some pattern char
                }
                else{
                    m[pattern[i]] = s;
                    set_string.insert(s);
                }
            }
            }
            else return false ;
        }
        if(input>>s)return false ;//more string compared to pattern
        return true;
    }
};