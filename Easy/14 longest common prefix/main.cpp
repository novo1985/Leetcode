#include <iostream>
#include <string>
#include <vector>
using namespace std;

/** common prefix == common substring(0, i)
 *  index j for vector strs: 0,1,2,...,n-1
 *  index i for strs[0]: 0,1,2,..strs[0].size()-1
 *  find the max value of index, until strs[j][i] != strs[j+1][i] or strs[j+1] doesnot hold the [i]
 *  return i-1
 *  Base Case: if vector is empty or contains only one string */

class Solution{
public:
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()){ return ""; }
    if(strs.size()==1){ return strs[0]; }
    int n = strs.size();
    for(int i = 0; i < strs[0].size();i++){
      for(int j = 0; j < n - 1; j++){
        if(strs[j][i] != strs[j+1][i] || i > strs[j+1].size()-1){
          //substr return substring[0, i) == [0, i-1]
          return strs[0].substr(0, i);
        }
      }
    }
    //otherwise all chars within strs[0] are common char
    return strs[0];
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}