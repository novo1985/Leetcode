#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* Given two binary strings, return their sum (also a binary string). */

class Solution {
public:
    string addBinary(string a, string b) {
      int n = max(a.size()-1, b.size()-1);
      int carry = 0;
      string res ="";
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      for(int k = 0; k <= n; k++) {
        //string to int a[k] = "1" ==> a_digit = 1 (a_digit = a[k] - '0')
        int a_digit = k < a.size() ? stoi(string(1, a[k])) : 0; // if no digits, using '0'
        int b_digit = k < b.size() ? stoi(string(1, b[k])) : 0;
        int sum = a_digit + b_digit + carry; // possible value: 0, 1, 2, 3
        carry = sum / 2;
        res = res + to_string(sum % 2);
      }
      if(carry == 1){
        res.push_back('1');
      }
      reverse(res.begin(),res.end());
      return res;
    }
};