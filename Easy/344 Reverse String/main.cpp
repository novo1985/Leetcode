#include <iostream>
#include <string>

using namespace std;

class RString {
public:
  RString();

  RString(string str): input(str){}

  string reverseString(string s);

public:
  string input;
};

string RString::reverseString(string s) {
  s = input;
  //reverse_iterator<string::iterator> rev_iter1;
  string RS(s.rbegin(), s.rend());
  return RS;
}

int main() {
  RString test;
  cout << test.reverseString("gaolei");
}