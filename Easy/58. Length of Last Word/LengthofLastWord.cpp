#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* Given a string s consists of upper/lower-case alphabets and empty
 * space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0. */

class Solution {
public:
    int lengthOfLastWord(string s) {
      if(s.empty()){return 0;}
      int i = s.size()-1;
      int len = 0;
      while(i>=0; && s[i] == ' ') { i--; }
      //find the index of i (backward)

      while(i>=0; && s[i] != ' ') {
        i--;
        len++;
      }
      return len;
    }
};