#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m1_s;
    unordered_map<char, int> m2_t;
    // check empty string first
    if(s.empty() && t.empty()){
      return true;
    }
    // every char in s and its frequency was paired and written into unordered_map container
    for(char cs : s){
      m1_s[cs]++;
    }
    for(char ct : t){
      m2_t[ct]++;
    }
    //check anagram
    bool b1 = true;
    bool b2 = true;
    for(auto& iter1 : m1_s){
      auto iter2 = m2_t.find(iter1.first);
      if((iter2 == m2_t.end()) || (iter1.second != iter2->second)){
         b1 = false;
      }
    }
    for(auto& iter1 : m2_t){
      auto iter2 = m1_s.find(iter1.first);
      if((iter2 == m1_s.end()) || (iter1.second != iter2->second)){
         b2 = false;
      }
    }

    if (b1 == true && b2 == true){return true;}

    return false;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}