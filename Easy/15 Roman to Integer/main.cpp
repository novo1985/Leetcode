#include <iostream>
#include <string>
using namespace std;

/** wiki rule of Roman: I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
 *  1) "5" never be repeated or substracted
 *  2) "1" can maximumly repeated three times
 *  3) suntraction rules */

class Solution{
public:
  int romanToInt(string s){
    // Int valuable holding the converted value
    int res = 0;
    char prev = '';
    //fetch each char of input string
    for(int i = 0; i < s.size(); i++){
      if(s[i] == 'M' && prev != 'C'){ res += 1000; }
      if(s[i] == 'M' && prev == 'C'){ res += 800; }

      if(s[i] == 'D' && prev != 'C'){ res += 500; }
      if(s[i] == 'D' && prev == 'C'){ res += 300; }

      if(s[i] == 'C' && prev != 'X'){ res += 100; }
      if(s[i] == 'C' && prev == 'X'){ res += 80; }

      if(s[i] == 'L' && prev != 'X'){ res += 50; }
      if(s[i] == 'L' && prev == 'X'){ res += 30; }

      if(s[i] == 'X' && prev != 'I'){ res += 10; }
      if(s[i] == 'X' && prev == 'I'){ res += 8; }

      if(s[i] == 'V' && prev != 'I'){ res += 5; }
      if(s[i] == 'V' && prev == 'I'){ res += 3; }

      if(s[i] == 'I'){ res += 1; }

      //update the prev char
      prev = s[i];
    }
      return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}