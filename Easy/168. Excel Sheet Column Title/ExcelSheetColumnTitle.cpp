#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/* Given a positive integer, return its corresponding column
 * title as appear in an Excel sheet.*/

class Solution {
public:
    string convertToTitle(int n) {
      unordered_map<int, char> m;
      string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      for(int i = 1; i < 27; i++){
        m[i] = temp[i-1];
      }
    }
};

class Solution{
public:
    string convertToTitle(int n) {
      string res = "";
      while(n>0){
        if(n%26 == 0){
          res = 'Z' + res;
          n = n/26 - 1;
        }
        else{
          res = char(n%26 - 1 + 'A') + res;
          n = n/26;
        }
      }
      return res;
    }
};








