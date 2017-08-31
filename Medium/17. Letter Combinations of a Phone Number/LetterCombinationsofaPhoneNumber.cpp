#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) **********/

 class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      if(digits.empty()) { return res; }
      string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 0-9
      letterCombinationsDFS(digits, dict, 0, "", res);
      /* input string: digits, dictionary: dict[], start level: index i = 0, output string: "",
       * final return value : vector<string> res */
      return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int index, string output,
            vector<string> res){
      // ending condition: index == digits.size()  From 0 -> size()-1
      if(index == digits.size()){
        res.push_back(output);
        return;
      }
      else{
        string letter = dict[digits[index] - '2'];
        for(int i = 0; i < letter.size(); i++){
          output[index] = letter[i];
          letterCombinationsDFS(digits, dict[], index + 1, output, res);
        }
      }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
        if (level == digits.size()) res.push_back(out);
        else {
            string str = dict[digits[level] - '2'];
            for (int i = 0; i < str.size(); ++i) {
                out.push_back(str[i]);
                letterCombinationsDFS(digits, dict, level + 1, out, res);
                out.pop_back();
            }
        }
    }
};



