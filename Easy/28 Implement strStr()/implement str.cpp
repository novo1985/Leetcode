#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
  int strStr(string haystack, string needle){
    if (needle.empty()) { return 0;}
    int n = haystack.size();
    int m = needle.size();
    if (m > n) {return -1;}
    for(int i = 0; i < n-m+1; i++){
      int j = 0;
      for(j = 0; j < m; j++){
        if(haystack[i+j] != needle[j]) { break; }
      }
      if (j == m){
        return i;
      }
    }
    return -1;
  }
};