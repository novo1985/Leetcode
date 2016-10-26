#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    string str;
    vector<string> FB;
    for(int i = 1; i < n + 1; i++){
        if(i%3 != 0 && i%5 !=0){
          str = to_string(i);
          str += "\n";
        }
        else if(i%3 == 0 && i%5 != 0){
          str = "Fizz";
          str += "\n";
        }
        else if(i%3 != 0 && i%5 == 0){
          str = "Buzz";
          str += "\n";
        }
        else if(i%3 == 0 && i%5 == 0){
          str = "FizzBuzz";
          str += "\n";
        }
        FB.push_back(str);
      }
      return FB;
  }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}