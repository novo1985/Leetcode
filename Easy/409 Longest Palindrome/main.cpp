#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
      /** First thinking: using hash_table to record every char's frequency
    *   the longest palindrome contains all char with frequency of even number plus the char with odd number frequency minus 1
    * */
      unordered_map<char, int> m;
      for(char c : s){
        // [] is a writing operation, which insert and update pair(char, frequency).
        m[c]++;
      }
      int len = 0;
      int odd = 0;
      int count = 0;
      for(auto iter = m.begin(); iter != m.end(); iter++){
        if((iter->second) % 2 == 0){
          len += iter->second;
        }
        else{
          count = 1;
          odd += (iter->second - 1);
        }
      }
      odd += count;
      len += odd;

      cout << "the maximum length of palindrome is " << len << endl;
      return len;
    }
};

int main() {
  Solution test;
  string s = "ababababcdcdcdcdeeefffff";
  test.longestPalindrome(s);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}