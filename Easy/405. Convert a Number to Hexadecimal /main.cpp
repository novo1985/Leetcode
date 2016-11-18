#include <iostream>
#include <string>
#include <vector>
using namespace std;
#if 0
bool pred(const int & a) {
  return a != 0;
};
#endif

class Solution {
public:
    string toHex(int num) {
      //15 = 0000000000000000...1111 = 0000000f
      /**const int c = 0xF;
      int temp = 0;
      string res;
      vector<int> byte(8, 0);
      if(num == 0){ return "0";}

      for (auto i = 7; i >= 0; i--) {
          temp = num & c;
          byte.at(i) = temp;
          num >>= 4;
        //cout << temp <<endl;
      }
      //reverse(byte.begin(), byte.end());
      auto iter = find_if(byte.begin(), byte.end(), [] (const int& num) { return num != 0; });
      byte.erase(byte.begin(), iter);

      for(auto b_i(byte.cbegin()); b_i != byte.cend(); b_i++) {
          int rem = *b_i % 16;
          if(rem > 9){
            res += 'a' + rem - 10;
          }
          else{
            res += rem + '0';
          }
      }

      return res;
       **/
      const int c = 0xF;
      int temp = 0;
      string res;
      if(num == 0){ return "0";}
      for(int i = 0; i < 8; i++){
        temp = (num >> (7-i)*4) & c;
          int remainder = temp % 16;
          if(remainder > 9){
            res += 'a' + remainder - 10;
          }
          else{
            res += remainder + '0';
          }
        }
      auto iter = find_if(res.begin(), res.end(), [] (const char& c) { return c != '0'; });
      res.erase(res.begin(), iter);
      return res;
    }
};

int main() {
  Solution test;

  cout << "Hex is " << test.toHex(16) << endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}