#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
  string countAndSay(int n){
    if(n < 0) {return "";}
    vector<string> str(n+1, "");
    str[0] = ""; // n=0
    str[1] = "1"; // n=1
    str[2] = "11";
    char curr = '';
    int count = 1;
    for(int i = 3; i < n; i++){
      curr = str[i-1][0];
      for(int k = 1; k < str[i-1].size(); k++){
        if(str[i-1][k] == curr){
          count++;
        }
        else{
          str[i] = str[i] + to_string(count);
          str[i].push_back(curr);
          curr = str[i-1][k];
          count = 1;
        }
      }
    }
    return str[n];
  }
};