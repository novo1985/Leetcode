#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string addStrings(string num1, string num2) {
/**
        int n1 = 0;
        int n2 = 0;
        int sum = 0;
        for(int i = 0; i < num1.size(); i++){
            n1 += pow(10, (num1.size() - 1 - i)) * num1[i];
        }
        for(int j = 0; j < num2.size(); j++){
            n2 += pow(10, (num2.size() - 1 - j)) * num2[j];
        }
        sum = n1 + n2;
        cout << "the sum of two numbers is " << sum << endl;
        **/
    int carry = 0;
    int len1 = num1.size();
    int len2 = num2.size();
    string num;
    //convert int between string, need "0"
    for(int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--){
      int temp = 0;
      if (i >= 0)
      {
        temp += num1[i] - '0';
      }
      if (j >= 0)
      {
        temp += num2[j] - '0';
      }
      if (carry)
      {
        ++temp;
      }
      carry = temp / 10;
      temp = temp % 10;

      num = char(temp + '0') + num;
    }
    if (carry)
    {
      num = char(carry + '0') + num;
    }
    return num;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}