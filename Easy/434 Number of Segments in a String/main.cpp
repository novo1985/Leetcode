#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
  int countSegments(std::string s){
    int count = 0;
    int pos = 0;
    // using " "(string) or ' '(char) for space key .
    char search_char = ' ';

    /*
     * this code can not deal with the special string "     " or "my     name    "

     while(!s.empty()){
      count++;
      pos = s.find(search_str);
      if(pos == -1){
        // delete the whole s string
        s.erase(0);
      }
      else{
        // delete the first segment
        s.erase(0, pos + 1);
      }
    }
    */

    for(int i = 0; i < s.size(); i++){
      if(s[i] == ' ') continue;
      count++;
      while(s[i] != ' ' && i < s.size()) { i++;}
    }
    return count;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}