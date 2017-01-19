#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//Write a function that takes a string as input and reverse only the vowels of a string.
class Solution{
public:
  /*****
string reverseVowels(string s){

  // Vowels letter A,E,I,O,U, a, e, i , o ,u (it should be case sensitive)
  unordered_map<int, string::iterator> m_all; // key is the index of letter, value is iterator of string
  string target = "aeiouAEIOU";
  vector<int> pos_vowel; // to store the positions of found vowel letters

  // store all letters into hash_table (key and value of iterator)
  for(int i = 0; i < s.size(); ++i){
    *m_all[i] = s[i];
    for(auto v : target){
      if(s[i] == v){  // record the positions of vowel letters
        pos_vowel.push_back(i);
      }
    }
  }
  // reverse vowel letter within string
  vector<int> temp = pos_vowel;
  reverse(temp.begin(), temp.end());
  for(int i = 0; i < pos_vowel.size(); ++i){
    char ch_temp2;
     ch_temp2= *m_all[temp[i]];
    *m_all[pos_vowel[i]] =  ch_temp2;
  }
  return s;

  *****/

  //method2: using double pointer to reverse string
  bool isvowel(char x){
    x = tolower(x);
    string target = "aeiou" ;
    for(auto v : target){
      if(x == v){
        return true;
      }
        return false;
    }
  }

  string reverseVowels(string s){
    int L = 0;
    int R = s.size()-1;
    while(L < R){
      while(L < R && !isvowel(s[L])){++L;}
      while(L < R && !isvowel(s[R])){++R;}
      if(L >= R) break;
      swap(s[L], s[R]);
    }
    return s;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}