#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    unordered_map<char, int> m;
    string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int val = 1;
    for(int i = 0; i < temp.size(); i++){
      m.insert(make_pair(temp[i], val));
      val++;
    }

    if(s.size() == 0){
      return 0;
    }

    int col = 0;

    for(int i = 0; i < s.size(); i++){

      auto search = m.find(s[i]);

      if(search != m.end()){
        int temp = search->second;
      }
      int carry = pow(26, (s.size()-1-i));
      col = carry * temp + col;

    }
    return col;
  }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}